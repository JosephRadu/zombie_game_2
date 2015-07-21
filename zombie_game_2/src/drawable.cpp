#include "drawable.h"


drawable::drawable()
{
	iSize = _iNodeSize;
	setPosition(0,0);
	sf::Color rgb(20,235,20);
	sfColour = rgb;
}
void drawable::colour(sf::Color colour)
{
	sfColour = colour;
}

void drawable::colour(int r, int g, int b)
{
	sf::Color rgb(r,g,b);
	sfColour = rgb;
}

void drawable::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::RectangleShape shape(sf::Vector2f(iSize, iSize));
	shape.setFillColor(sfColour);
	shape.setOrigin(iSize/ 2, iSize / 2);
	shape.setPosition(v2dPosition.x(), v2dPosition.y());
	target.draw(shape);
}