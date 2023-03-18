#include <iostream>
#include "Mirror.h"
#include "FocusController.h"
#include "ModeController.h"
#include "Segment.h"
#include "Arc.h"

Mirror::Mirror(Corner^ begin, Corner^ end)
{
	mirrorType = MirrorType::Flat;
	this->begin = begin;
	this->end = end;
	line = gcnew Segment(begin->getPosition(), end->getPosition());
}

Mirror^ Mirror::copy()
{
	return gcnew Mirror(begin, end);
}

void Mirror::draw(System::Drawing::Graphics^ g)
{
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	if (ModeController::getInstance()->getMode() == ModeController::ModeType::RoomEditing &&
		FocusController::getInstance()->getFocusedMirror() == this) {
		pen->Color = System::Drawing::Color::Blue;
		pen->Width = 3;
	}

	getLine()->draw(g, pen);
}

Vector^ Mirror::getTangent(Vector^ pos)
{
	Vector^ tanget = line->getTangent(pos);
	if (mirrorType == MirrorType::Convex)
		tanget = -tanget;
	return tanget;
}

/*Mirror::Mirror(Mirror^ other)
{
	begin = other->getBegin();
	end = other->getEnd();
}*/

Corner^ Mirror::getBegin()
{
	return begin;
}

void Mirror::setBegin(Corner^ corner)
{
	begin = corner;
}

Corner^ Mirror::getEnd()
{
	return end;
}

void Mirror::setEnd(Corner^ corner)
{
	end = corner;
}

void Mirror::update()
{
	setMirrorType(mirrorType);
	if (mirrorType == MirrorType::Concave) {
		line->setBegin(end->getPosition());
		line->setEnd(begin->getPosition());
	}
	else {
		line->setBegin(begin->getPosition());
		line->setEnd(end->getPosition());
	}
}

Line^ Mirror::getLine()
{
	return line;
}

void Mirror::reverse()
{
	Corner^ tmp = begin;
	begin = end;
	end = tmp;

	line->reverse();
}

double Mirror::getRadius()
{
	return radius;
}

void Mirror::setRadius(double radius)
{
	this->radius = radius;
	if (mirrorType == MirrorType::Convex)
		line = gcnew Arc(begin->getPosition(), end->getPosition(), radius);
	else if(mirrorType == MirrorType::Concave)
		line = gcnew Arc(end->getPosition(), begin->getPosition(), radius);
}

Mirror::MirrorType Mirror::getMirrorType()
{
	return mirrorType;
}

void Mirror::setMirrorType(MirrorType mirrorType)
{
	this->mirrorType = mirrorType;
	if (mirrorType == MirrorType::Flat) {
		line = gcnew Segment(begin->getPosition(), end->getPosition());
	}
	else if (mirrorType == MirrorType::Convex) {
		Arc^ arc = gcnew Arc(begin->getPosition(), end->getPosition(), radius);
		radius = arc->getRadius();
		line = arc;
	}
	else if (mirrorType == MirrorType::Concave) {
		Arc^ arc = gcnew Arc(end->getPosition(), begin->getPosition(), radius);
		radius = arc->getRadius();
		line = arc;
	}
}
