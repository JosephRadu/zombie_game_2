#include "entity.h"


entity::entity()
{

}

// Return cell coordinates depending on current world coordinates.
vector2d entity::nodePosition()
{
	vector2d v2dResult ( int(v2dPosition.x()/16), int(v2dPosition.y()/16));
	return v2dResult;
}

// Setting cell coordinates will automatically set objects position to the cell.
void entity::setNodePosition(int x, int y)
{
	v2dPosition.set(x*_iNodeSize+_iNodeSize*0.5,y*_iNodeSize+_iNodeSize*0.5);
}

void entity::setNodePosition(vector2d node)
{
	v2dPosition.set(node.x()*_iNodeSize+iSize*0.5,node.y()*_iNodeSize+iSize*0.5);
}

int entity::size()
{
	return iSize;
}


vector2d entity::position()
{
	return v2dPosition;
}

float entity::rotation()
{
	return fRotation;
}

void entity::setPosition(vector2d pos)
{
	v2dPosition.set(pos);
}

void entity::setPosition(float x, float y)
{
	v2dPosition.set(x, y);
}

void entity::setRotation(float fRotate)
{
	fRotation = fRotate;
}
