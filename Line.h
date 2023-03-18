#pragma once
#include "Vector.h"
//#include "Mirror.h"

ref class Line
{
public:
	Line(Vector^ begin, Vector^ end);

	Line(Line^ other);

	virtual void draw(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen) = 0;

	virtual Vector^ getNormal(Vector^ position) = 0;

	virtual Vector^ getTangent(Vector^ position);

	virtual double getDistance(Vector^ position) = 0;

	virtual Vector^ getNearest(Vector^ position) = 0;

	virtual System::Collections::Generic::List<Vector^>^ getSegmentIntersection(Vector^ a, Vector^ b) = 0;

	virtual void update();

	virtual void reverse();

	Vector^ getBegin();
	void setBegin(Vector^ pos);

	Vector^ getEnd();
	void setEnd(Vector^ pos);

protected:
	Vector^ begin;
	Vector^ end;
};

