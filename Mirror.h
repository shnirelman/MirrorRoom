#pragma once
#include "Corner.h"
#include "Focusable.h"
#include "Line.h"

ref class Mirror : public Focusable
{
public:
	enum class MirrorType {Flat, Convex, Concave};

	static const double CollisionRadius = 8;

	Mirror(Corner^ begin, Corner^ end);

	//Mirror(Mirror^ other);

	Mirror^ copy();

	void draw(System::Drawing::Graphics^ g);

	Vector^ getTangent(Vector^ pos);

	//virtual Vector^ getNormal(Vector^ position) = 0;

	//virtual double getDistance(Vector^ position) = 0;

	Corner^ getBegin();
	void setBegin(Corner^ corner);
	
	Corner^ getEnd();
	void setEnd(Corner^ corner);

	void update();

	Line^ getLine();

	void reverse();

	double getRadius();

	void setRadius(double radius);

	MirrorType getMirrorType();

	void setMirrorType(MirrorType mirrorType);

private:
	MirrorType mirrorType;
	Corner^ begin;
	Corner^ end;
	Line^ line;
	double radius;
};

