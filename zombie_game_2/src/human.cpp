#include "human.h"

Human::Human()
{
	iSize = _iNodeSize;
	sf::Color rgb(100,110,230);
	sfColour = rgb;
}

Human::Human(int nodeX, int nodeY)
{
	setNodePosition(nodeX, nodeY);
	iSize = _iNodeSize;
	sf::Color rgb(100,110,230);
	sfColour = rgb;
	iHealth = 100;
	iMaxHealth = 100;
}
