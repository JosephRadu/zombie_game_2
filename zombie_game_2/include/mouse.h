#ifndef MOUSE_H
#define MOUSE_H

#include "vector2d.h"

class Mouse
{
private:
	bool bLeft;
	bool bRight;
	vector2d v2dPosition;
public:
	Mouse();

	bool left();
	bool right();

	void leftPressed(bool bLeftIn);
	void rightPressed(bool bRightIn);

	void setX(float x);
	void setY(float y);
	void setPosition(vector2d v2dPos);
	void setPosition(float x, float y);

	vector2d position();

};

#endif