#pragma once
#include "Corner.h"
#include "Mirror.h"

ref class Room
{
public:
	static Room^ getInstance();

	void draw(System::Drawing::Graphics^ g);

	void addCorner(int pos, Corner^ corner);

	void removeCorner(Corner^ corner);

	System::Collections::Generic::List<Corner^>^ getCorners();
	System::Collections::Generic::List<Mirror^>^ getMirrors();

	double getWidth();
	void setWidth(double width);

	double getHeight();
	void setHeight(double height);

	void update();

	void reverse();

	void divide();

	void removeFocusedCorner();

private:
	Room();
	
	static Room^ instance;
	System::Collections::Generic::List<Corner^>^ corners;
	System::Collections::Generic::List<Mirror^>^ mirrors;

	double width;
	double height;
};

