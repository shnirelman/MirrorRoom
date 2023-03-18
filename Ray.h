#pragma once
#include "Vector.h"
#include "Room.h"
#include "Segment.h"

ref class Ray
{
public:
	static Ray^ getInstance();

	void draw(System::Drawing::Graphics^ g);

	void makeValid();

	Vector^ getStart();

	void setStart(Vector^ pos);

	void calcStart();

	double getAngle();

	void setAngle(double angle);

	int getIterationsCount();

	void setIterationsCount(int count);
private:
	Ray();

	void build();

	

	static Ray^ instance;

	Vector^ start;
	double angle;
	Mirror^ startMirror;

	double tangetLength = 50;

	System::Collections::Generic::List<Vector^>^ points;

	int iterationsCount = 6;
};

