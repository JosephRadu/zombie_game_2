#ifndef CREATOR_H
#define CREATOR_H

#include "wall.h"

class Creator
{
public:
	Wall* createWall(int x, int y)
	{
		Wall * wall;
		wall = new Wall(x, y);
		return wall;
	}
};
#endif