#include "FlatMirror.h"
#include "FocusController.h"
#include <algorithm>

FlatMirror::FlatMirror(Corner^ begin, Corner^ end) : Mirror(begin, end)
{
	
}

/*void FlatMirror::draw(System::Drawing::Graphics^ g)
{
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	if (FocusController::getInstance()->getFocusedMirror() == this) {
		pen->Color = System::Drawing::Color::Blue;
		pen->Width = 3;
	}
		
	g->DrawLine(pen,
		System::Drawing::Point(begin->getPosition()->getX(),
			begin->getPosition()->getY()),
		System::Drawing::Point(end->getPosition()->getX(),
			end->getPosition()->getY()));
}*/

Vector^ FlatMirror::getNormal(Vector^ position)
{
	Vector^ a = end->getPosition() - begin->getPosition();
	return gcnew Vector(-a->getY(), a->getX());
}

double FlatMirror::getDistance(Vector^ position)
{
	Vector^ a = end->getPosition() - begin->getPosition();
	Vector^ b = position - begin->getPosition();
	Vector^ c = position - end->getPosition();
	if (a->scalarProduct(b) > -Vector::EPS &&
		(-a)->scalarProduct(c) > -Vector::EPS) {
		return abs(a->vectorProduct(b)) * 2 / a->getLength();
	}
	else {
		return std::min(end->getPosition()->getDistance(position),
			begin->getPosition()->getDistance(position));
	}
}

double FlatMirror::getLine(Vector^ position)
{
	return line;
}
