#include "mouse.h"

Mouse::Mouse()
{
	bLeft = false;
	bRight = false;
}

bool Mouse::left()
{
	return bLeft;
}
bool Mouse::right()
{
	return bRight;
}

void Mouse::leftPressed(bool bLeftIn)
{
	bLeft = bLeftIn;
}
void Mouse::rightPressed(bool bRightIn)
{
	bRight = bRightIn;
}

void Mouse::setX(float x)
{
	v2dPosition.setX(x);
}
void Mouse::setY(float y)
{
	v2dPosition.setY(y);
}
void Mouse::setPosition(vector2d v2dPos)
{
	v2dPosition.set(v2dPos);
}
void Mouse::setPosition(float x, float y)
{
	v2dPosition.set(x,y);
}

vector2d Mouse::position()
{
	return v2dPosition;
}