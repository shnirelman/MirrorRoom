#pragma once
#include "Line.h"
ref class Arc :
    public Line
{
public:
    Arc(Vector^ begin, Vector^ end);

    Arc(Vector^ begin, Vector^ end, double radius);

    virtual void draw(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen) override;

    virtual Vector^ getNormal(Vector^ position) override;

    virtual double getDistance(Vector^ position) override;

    virtual Vector^ getNearest(Vector^ position) override;

    virtual System::Collections::Generic::List<Vector^>^ getSegmentIntersection(Vector^ a, Vector^ b) override;

    void calcCenter();

    double getRadius();
    
    void setRadius(double radius);

private:
    double MaxRadius = 10000.0;
    double radius;
    Vector^ center;
};

