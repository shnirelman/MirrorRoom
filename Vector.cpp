#include "Vector.h"
#include <math.h>

Vector::Vector()
{
    x = 0;
    y = 0;
}

Vector::Vector(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Vector::getX()
{
    return this->x;
}

void Vector::setX(double x)
{
    this->x = x;
}

double Vector::getY()
{
    return this->y;
}

void Vector::setY(double y)
{
    this->y = y;
}

double Vector::scalarProduct(Vector^ other)
{
    return x * other->getX() + y * other->getY();
}

double Vector::vectorProduct(Vector^ other)
{
    return x * other->getY() - y * other->getX();
}

double Vector::getLength()
{
    return sqrt(this->scalarProduct(this));
}

double Vector::getDistance(Vector^ other)
{
    return (this - other)->getLength();
}

Vector^ Vector::getNormal()
{
    return gcnew Vector(-y, x);
}

double Vector::getAngle()
{
    return atan2(y, x);
}

Vector^ Vector::normalize()
{
    double len = getLength();
    return gcnew Vector(x / len, y / len);
}

Vector^ Vector::operator=(Vector^ other)
{
    return gcnew Vector(other->getX(), other->getY());
}

Vector^ Vector::operator-()
{
    return gcnew Vector(-x, -y);
}

Vector^ Vector::operator+(Vector^ other)
{
    return gcnew Vector(x + other->getX(), y + other->getY());
}

Vector^ Vector::operator-(Vector^ other)
{
    return this + (-other);
}

Vector^ Vector::operator*(double mul)
{
    return gcnew Vector(x * mul, y * mul);
}

Vector::operator System::Drawing::Point()
{
    return System::Drawing::Point(x, y);
}
