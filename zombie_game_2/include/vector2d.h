#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>  

class vector2d
{
protected:
	float afData[2];
public:

    vector2d();
    vector2d(float allValues); 
    vector2d(float x, float y);
	void setX(float x);
	void setY(float y);
	void set(float x, float y);
	void set(vector2d vector);
	float x() const;
	float y() const;
    float angle(const vector2d& other) const;
    float dotProduct(const vector2d& other) const;
	float crossProduct(const vector2d& other) const;
    vector2d unitVector() const;
    float magnitude() const;
    vector2d subtract(const vector2d& other) const;
	vector2d subtract(float x, float y) const;
    vector2d add(const vector2d& other) const;
    vector2d multiply(const vector2d& other) const;
    vector2d scale(const float scalar) const; 
	bool operator==(const vector2d& other);
	bool operator!=(const vector2d& other);
};

#endif