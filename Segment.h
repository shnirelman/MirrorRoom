#pragma once
#include <math.h>
#include <algorithm>
#include "Line.h"
#include "Arc.h"

ref class Segment :
    public Line
{
public:
    Segment(Vector^ begin, Vector^ end);

    Segment(Segment^ other);

    virtual void draw(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen) override;

    virtual Vector^ getNormal(Vector^ position) override;

    virtual double getDistance(Vector^ position) override;

    virtual Vector^ getNearest(Vector^ position) override;

    virtual System::Collections::Generic::List<Vector^>^ getSegmentIntersection(Vector^ a, Vector^ b) override;
    

private:
    int sign(double x);

    double determinate(double a00, double a01, double a10, double a11);
};

