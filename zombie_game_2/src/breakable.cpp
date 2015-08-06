#include "breakable.h"

Breakable::Breakable()
{
	iSize = _iNodeSize;
	sf::Color rgb(219,188,81);
	sfColour = rgb;
}

Breakable::Breakable(int nodeX, int nodeY)
{
	setNodePosition(nodeX, nodeY);
	iSize = _iNodeSize;
	sf::Color rgb(219,188,81);
	sfColour = rgb;
	iHealth = 100;
	iMaxHealth = 100;
}

int Breakable::health()
{
	return iHealth;
}
void Breakable::setHealth(int i)
{
	iHealth = i;
}

int Breakable::maxHealth()
{
	return iMaxHealth;
}