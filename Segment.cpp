#include "Segment.h"
#include <math.h>
#include <iostream>

Segment::Segment(Vector^ begin, Vector^ end) : Line(begin, end)
{

}

Segment::Segment(Segment^ other) : Line(other)
{
	
}

void Segment::draw(System::Drawing::Graphics^ g, System::Drawing::Pen^ pen)
{
	g->DrawLine(pen, System::Drawing::Point(begin->getX(), begin->getY()),
			System::Drawing::Point(end->getX(), end->getY()));
}

Vector^ Segment::getNormal(Vector^ position)
{
	Vector^ a = end - begin;
	return gcnew Vector(-a->getY(), a->getX());
}

double Segment::getDistance(Vector^ position)
{
	Vector^ a = end - begin;
	Vector^ b = position - begin;
	Vector^ c = position - end;
	if (a->scalarProduct(b) > -Vector::EPS &&
		(-a)->scalarProduct(c) > -Vector::EPS) {
		return abs(a->vectorProduct(b)) * 2 / a->getLength();
	}
	else {
		return std::min(end->getDistance(position),
			begin->getDistance(position));
	}
}

Vector^ Segment::getNearest(Vector^ position)
{
	Vector^ a = end - begin;
	Vector^ b = position - begin;
	Vector^ c = position - end;
	if (a->scalarProduct(b) > -Vector::EPS &&
		(-a)->scalarProduct(c) > -Vector::EPS) {
		double d = a->vectorProduct(b) * 2 / a->getLength();
		Vector^ norm = a->getNormal()->normalize();
		Vector^ H = position - norm * d * 0.5;
		return H;
	}
	else {
		if (end->getDistance(position) < begin->getDistance(position))
			return end;
		else
			return begin;
	}
}

System::Collections::Generic::List<Vector^>^ Segment::getSegmentIntersection(Vector^ a, Vector^ b)
{
	System::Collections::Generic::List<Vector^>^ res = gcnew System::Collections::Generic::List<Vector^>();

	Vector^ c = this->begin;
	Vector^ d = this->end;

	if (sign((b - a)->vectorProduct(c - a)) * sign((b - a)->vectorProduct(d - a)) == 1)
		return res;

	if (sign((d - c)->vectorProduct(a - c)) * sign((d - c)->vectorProduct(b - c)) == 1)
		return res;

	Vector^ v = b - a;
	Vector^ u = d - c;

	double A1 = v->getY(), B1 = -v->getX(), C1 = v->getX() * a->getY() - v->getY() * a->getX();
	double A2 = u->getY(), B2 = -u->getX(), C2 = u->getX() * c->getY() - u->getY() * c->getX();

	double D = determinate(A1, B1, A2, B2);

	if (abs(D) < Vector::EPS)
		return res;

	double Dx = -determinate(C1, B1, C2, B2); 
	double Dy = -determinate(A1, C1, A2, C2);
	res->Insert(0, gcnew Vector(Dx / D, Dy / D));

	return res;
}

int Segment::sign(double x)
{
	if (x < -Vector::EPS)
		return -1;
	else if (x > Vector::EPS)
		return 1;
	else
		return 0;
}

double Segment::determinate(double a00, double a01, double a10, double a11)
{
	return a00 * a11 - a01 * a10;
}
