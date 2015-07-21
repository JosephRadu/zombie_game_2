#include "box.h"

bool box::isColliding(box &other)
{
	vector2d v2d;

	v2d.set(other.position().subtract(v2dPosition));
	
	float fDistance = v2d.magnitude() - iSize*0.5 - other.size()*0.5;

	if (fDistance < 0)
	{
		return true;
	}
	else return false;

}