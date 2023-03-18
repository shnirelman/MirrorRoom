#pragma once
#include "Vector.h"
#include "Focusable.h"

ref class Corner : public Focusable
{
public:
	Corner(Vector^ position);

	Vector^ getPosition();

	void setPosition(Vector^ position);

	double getRadius();

	//virtual void draw(System::Windows::Forms::PaintEventArgs^ e);
	virtual void draw(System::Drawing::Graphics^ g);
private:
	Vector^ position;
	double radius = 5.0; // нужен для рисования и проверки на коллизии
};

