#ifndef CREATOR_H
#define CREATOR_H

#include "human.h"
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

	Breakable* createBreakable(int x, int y)
	{
		Breakable * breakable;
		breakable = new Breakable(x, y);
		return breakable;
	}

	Human* createHuman(int x, int y)
	{
		Human * human;
		human = new Human(x, y);
		return human;
	}

	Map* createMap()
	{
		Map * map;
		map = new Map();
		return map;
	}

};
#endif