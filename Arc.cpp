#include "Arc.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <limits>
#include <cstddef>

Arc::Arc(Vector^ begin, Vector^ end) : Line(begin, end)
{
    radius = (end - begin)->getLength();
    calcCenter();
}

Arc::Arc(Vector^ begin, Vector^ end, double radius) : Line(begin, end)
{
    if (radius < Vector::EPS || radius > MaxRadius + Vector::EPS) {
        this->radius = (end - begin)->getLength();
    }
    else {
        this->radius = radius;
    }
    
    calcCenter();
}

void Arc::draw(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen)
{
    calcCenter();
    Vector^ beg = begin - center;
    double beg_angle = atan2(beg->getY(), beg->getX());
    Vector^ en = end - center;
    double en_angle = atan2(en->getY(), en->getX());
    double delta_angle = atan2(en->vectorProduct(beg), en->scalarProduct(beg));
    if (delta_angle < 0) {
        delta_angle += 2 * acos(-1);
    }

    g->DrawArc(pen, float(center->getX() - radius), float(center->getY() - radius),
        radius * 2, radius * 2, 
        en_angle * 180 / acos(-1), delta_angle * 180 / acos(-1));
}

Vector^ Arc::getNormal(Vector^ position)
{
    calcCenter();
    return center - position;
}

double Arc::getDistance(Vector^ position)
{
    calcCenter();
    Vector^ beg = begin - center;
    double beg_angle = atan2(beg->getY(), beg->getX());
    Vector^ en = end - center;
    double en_angle = atan2(en->getY(), en->getX());
    double delta_angle = atan2(en->vectorProduct(beg), en->scalarProduct(beg));
    if (delta_angle < 0) {
        delta_angle += 2 * acos(-1);
    }

    Vector^ pos = position - center;
    double pos_delta_angle = atan2(pos->vectorProduct(beg), pos->scalarProduct(beg));
    if (pos_delta_angle < 0) {
        pos_delta_angle += 2 * acos(-1);
    }

    if(pos_delta_angle < delta_angle + Vector::EPS) {
        return abs(radius - pos->getLength());
    }
    else
        return std::min((position - begin)->getLength(),
            (position - end)->getLength());
}

Vector^ Arc::getNearest(Vector^ position)
{
    calcCenter();
    Vector^ beg = begin - center;
    double beg_angle = atan2(beg->getY(), beg->getX());
    Vector^ en = end - center;
    double en_angle = atan2(en->getY(), en->getX());
    double delta_angle = atan2(en->vectorProduct(beg), en->scalarProduct(beg));
    if (delta_angle < 0) {
        delta_angle += 2 * acos(-1);
    }

    Vector^ pos = position - center;
    double pos_delta_angle = atan2(pos->vectorProduct(beg), pos->scalarProduct(beg));
    if (pos_delta_angle < 0) {
        pos_delta_angle += 2 * acos(-1);
    }

    double pos_angle = atan2(pos->getY(), pos->getX());
    if (pos_delta_angle < delta_angle + Vector::EPS) {
        return center + (gcnew Vector(
            cos(pos_angle), sin(pos_angle))) * radius;
    }
    else
        if (position->getDistance(begin) <
            position->getDistance(end))
            return begin;
        else
            return end;
}

System::Collections::Generic::List<Vector^>^ Arc::getSegmentIntersection(Vector^ a, Vector^ b)
{
    calcCenter();

    System::Collections::Generic::List<Vector^>^ res = gcnew System::Collections::Generic::List<Vector^>();

    Vector^ v = b - a;
    double A = v->getY(), B = -v->getX(), C = v->getX() * a->getY() - v->getY() * a->getX();

    double denom = sqrt(A * A + B * B);

    A /= denom;
    B /= denom;
    C /= denom;
    
    double cx = center->getX(), cy = center->getY();
    double dist = abs(A * cx + B * cy + C);
    Vector^ norm = (gcnew Vector(A, B))->normalize();
    Vector^ H1 = center + norm * dist;
    Vector^ H2 = center - norm * dist;
    Vector^ H;
    if (abs(A * H1->getX() + B * H1->getY() + C) < abs(A * H2->getX() + B * H2->getY() + C))
        H = H1;
    else
        H = H2;

    if (dist > radius + Vector::EPS)
        ;
    else if (dist > radius - Vector::EPS) {
        res->Insert(0, H);
    }
    else {
        double d = sqrt(radius * radius - dist * dist);
        Vector^ u = (gcnew Vector(-B, A))->normalize();
        Vector^ P = H + u * d;
        Vector^ Q = H - u * d;
        res->Insert(0, P);
        res->Insert(1, Q);
    }

    for (int i = 0; i < res->Count; i++) {
        if (this->getDistance(res[i]) > Vector::EPS ||
            (b - a)->scalarProduct(res[i] - a) < -Vector::EPS ||
            (a - b)->scalarProduct(res[i] - b) < -Vector::EPS) {
            res->RemoveAt(i);
            i--;
        }
    }

    return res;
}

void Arc::calcCenter()
{
    if(radius < (end - begin)->getLength() / 2)
        radius = (end - begin)->getLength() / 2;
    double l = 0, r = MaxRadius;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;

        Vector^ center = (begin + end) * 0.5 - (end - begin)->getNormal()->normalize() * mid;
        double dist = (begin - center)->getLength();

        if (dist > radius)
            r = mid;
        else
            l = mid;
    }

    this->center = (begin + end) * 0.5 - (end - begin)->getNormal()->normalize() * l;
}

double Arc::getRadius()
{
    return radius;
}

void Arc::setRadius(double radius)
{
    this->radius = radius;
    calcCenter();
}
