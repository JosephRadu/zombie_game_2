#ifndef CREATOR_H
#define CREATOR_H

#include "wall.h"
#include "map.h"

class Creator
{
public:
	Wall* createWall(int x, int y)
	{
		Wall * wall;
		wall = new Wall(x, y);
		return wall;
	}

	Map* createMap()
	{
		Map * map;
		map = new Map();
		return map;
	}

};
#endif