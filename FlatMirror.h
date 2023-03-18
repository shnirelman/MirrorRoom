#pragma once
#include "Mirror.h"
#include "Segment.h"

ref class FlatMirror :
    public Mirror
{
public:
	FlatMirror(Corner^ begin, Corner^ end);

	

	//virtual void draw(System::Drawing::Graphics^ g) override;

	//virtual Vector^ getNormal(Vector^ position) override;

	//virtual double getDistance(Vector^ position) override;

	virtual Line getLine(Vector^ position) override;



private:
	Segment^ line;
};

