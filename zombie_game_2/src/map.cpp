#include "map.h"

Map::Map()
{
	sName = "unnamed";
	sAuthor = "anon";
	sDescription = "none";


}

int Map::width()
{
	return iWidth;
}
int Map::height()
{
	return iHeight;
}

void Map::setNode(int x, int y, char c)
{
	world[x][y] = c;
}

char Map::node(int x, int y)
{
	return world[y][x];
}

void Map::setWidth(int width)
{
	iWidth = width;
}

void Map::setHeight(int height)
{
	iHeight = height;
}

string Map::name()
{
	return sName;
}

string Map::author()
{
	return sAuthor;
}

string Map::description()
{
	return sDescription;
}

void Map::setName(string name)
{
	sName = name;
}
void Map::setAuthor(string author)
{
	sAuthor = author;
}
void Map::setDescription(string description)
{
	sDescription = description;
}
