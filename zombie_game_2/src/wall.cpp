#include "wall.h"

Wall::Wall()
{
	iSize = _iNodeSize;
	sf::Color rgb(160,120,130);
	sfColour = rgb;
}

Wall::Wall(int nodeX, int nodeY)
{
	setNodePosition(nodeX, nodeY);
	iSize = _iNodeSize;
	sf::Color rgb(160,120,130);
	sfColour = rgb;
}