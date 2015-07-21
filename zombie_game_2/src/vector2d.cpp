#include "vector2d.h"

vector2d::vector2d()
{
}

vector2d::vector2d(float allValues)
{
}

vector2d::vector2d(float x, float y)
{
	afData[0] = x;
	afData[1] = y;
}
float vector2d::x() const
{
	return afData[0];
}
float vector2d::y() const
{
	return afData[1];
}
void vector2d::setX(float x)
{
	afData[0] = x;
}
void vector2d::setY(float y)
{
	afData[1] = y;
}
void vector2d::set(float x, float y)
{
	afData[0] = x;
	afData[1] = y;
}
void vector2d::set(vector2d vector)
{
	afData[0] = vector.x();
	afData[1] = vector.y();
}

float vector2d::dotProduct(const vector2d& other) const
{
	float dotProduct = (afData[0] * other.x()) + (afData[1] * other.y());
	return dotProduct;
}

float vector2d::angle(const vector2d& other) const
{
	float angle = cos(dotProduct(other) / other.magnitude() * sqrt(afData[0] * afData[0] + afData[1] * afData[1]));
	return angle;
}

float vector2d::crossProduct(const vector2d& other) const
{
	float crossProduct = (afData[0] * other.y() - afData[1] * other.x());
	return crossProduct;
}

vector2d vector2d::unitVector() const
{
	vector2d unitVector(afData[0] / sqrt(afData[0] * afData[0] + afData[1] * afData[1]), afData[1] / sqrt(afData[0] * afData[0] + afData[1] * afData[1]));
	return unitVector;
}

float vector2d::magnitude() const 
{
	float magnitude = sqrt(afData[0] * afData[0] + afData[1] * afData[1]);
	return magnitude;
}

vector2d vector2d::subtract(const vector2d& other) const
{
	vector2d subtract(afData[0] - other.x(), afData[1] - other.y());
	return subtract;
}

vector2d vector2d::subtract(float x, float y) const
{
	vector2d subtract(afData[0] - x, afData[1] - y);
	return subtract;
}

vector2d vector2d::add(const vector2d& other) const
{
	vector2d add(afData[0] + other.x(), afData[1] + other.y());
	return add;
}

vector2d vector2d::multiply(const vector2d& other) const
{
	vector2d multiply(afData[0] * other.x(), afData[1] * other.y());
	return multiply;
}

vector2d vector2d::scale(const float scalar) const
{
	vector2d scale(afData[0] * scalar, afData[1] * scalar);
	return scale;
}

bool vector2d::operator==(const vector2d& other)
{
	return afData[0] == other.x() && afData[1] == other.y();
}

bool vector2d::operator!=(const vector2d& other)
{
	int i = 0;

	if (afData[0] == other.x())
	{
		i++;
	}
	if (afData[1] == other.y())
	{
		i++;
	}
	return i != 2;
}

