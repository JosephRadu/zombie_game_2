#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class drawable : public sf::Drawable, public entity
{
protected:
	sf::Color sfColour;
public:
	drawable();
	void colour(sf::Color colour);
	void colour(int r, int g, int b);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	//virtual void update() = 0;
};
	
#endif