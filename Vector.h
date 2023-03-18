#pragma once
ref class Vector
{
public:
	static const double EPS = 1e-4;

	Vector();
	Vector(double x, double y);

	double getX();
	void setX(double x);
	double getY();
	void setY(double y);

	double scalarProduct(Vector^ other);

	double vectorProduct(Vector^ other);

	double getLength();

	double getDistance(Vector^ other);

	Vector^ getNormal();

	double getAngle();

	Vector^ normalize();

	Vector^ operator=(Vector^ other);

	Vector^ operator-();

	Vector^ operator+(Vector^ other);

	Vector^ operator-(Vector^ other);

	Vector^ operator*(double mul);

	operator System::Drawing::Point();

private:
	double x, y;

};

