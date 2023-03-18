#include "Ray.h"
#include "ModeController.h"
#include <iostream>

Ray^ Ray::getInstance()
{
    if (!instance)
        instance = gcnew Ray();
    return instance;
}

void Ray::draw(System::Drawing::Graphics^ g)
{   
    makeValid();
    calcStart();
    build();

    System::Drawing::Pen^ pen = gcnew
        System::Drawing::Pen(System::Drawing::Color::Red, 2);

    if (ModeController::getInstance()->getMode() ==
        ModeController::ModeType::RayCasting) {
        Vector^ tangent = startMirror->getLine()->getTangent(start);
        g->DrawLine(pen, System::Drawing::Point(start - tangent * tangetLength * 0.5),
            System::Drawing::Point(start + tangent * tangetLength * 0.5));
    }

    pen->Width = 1;

    for (int i = 0; i + 1 < points->Count; i++) {
        g->DrawLine(pen, System::Drawing::Point(points[i]),
            System::Drawing::Point(points[i + 1]));
    }
}

void Ray::makeValid()
{
    if (!startMirror) {
        startMirror = Room::getInstance()->getMirrors()[0];
        start = (startMirror->getBegin()->getPosition() + 
            startMirror->getEnd()->getPosition()) * 0.5;
        angle = 90;
    }
}

Vector^ Ray::getStart()
{
    return start;
}

void Ray::build()
{
    System::Collections::Generic::List<Mirror^>^ mirrors = Room::getInstance()->getMirrors();
    points = gcnew System::Collections::Generic::List<Vector^>();
    points->Insert(0, start);

    Vector^ tangent = startMirror->getTangent(start);
    double curAngle = tangent->getAngle() + angle * acos(-1) / 180 + acos(-1);

    for(int iteration = 0; iteration < iterationsCount; iteration++) {
        Vector^ A = points[points->Count - 1];
        Vector^ v = gcnew Vector(cos(curAngle), sin(curAngle));
        
        double dist = 1000;
        Vector^ B = A + v * 0.01;
        Vector^ C = A + v * dist;
        
        Vector^ res = C;
        Mirror^ mirror = nullptr;

        for (int i = 0; i < mirrors->Count; i++) {
            System::Collections::Generic::List<Vector^>^ rs =
                mirrors[i]->getLine()->getSegmentIntersection(B, C);
            for (int j = 0; j < rs->Count; j++) {
                double d = v->scalarProduct(rs[j] - B);
                if (d > Vector::EPS && d < dist) {
                    dist = d;
                    res = rs[j];
                    mirror = mirrors[i];
                }
            }
        }

        points->Insert(points->Count, res);
        if (!mirror)
            break;

        Vector^ norm = mirror->getLine()->getNormal(res);
        double incidenceAngle = atan2(norm->vectorProduct(B - res), norm->scalarProduct(B - res));
        curAngle = norm->getAngle() - incidenceAngle;
    }
}

void Ray::calcStart()
{
    System::Collections::Generic::List<Mirror^>^ mirrors = Room::getInstance()->getMirrors();
    double dist = 1e9;
    Vector^ res = start;
    for (int i = 0; i < mirrors->Count; i++) {
        double d = mirrors[i]->getLine()->getDistance(start);
        if (d < dist) {
            dist = d;
            res = mirrors[i]->getLine()->getNearest(start);
            startMirror = mirrors[i];
        }
    }

    start = res;
}

double Ray::getAngle()
{
    return angle;
}

void Ray::setAngle(double angle)
{
    this->angle = angle;
}

int Ray::getIterationsCount()
{
    return iterationsCount;
}

void Ray::setIterationsCount(int count)
{
    if (count >= 1 && count <= 100)
        iterationsCount = count;
}

void Ray::setStart(Vector^ pos)
{
    start = pos;
    calcStart();
}



Ray::Ray()
{
}
