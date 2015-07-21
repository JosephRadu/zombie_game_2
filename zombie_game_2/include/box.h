#ifndef BOX_H
#define BOX_H

#include "drawable.h"

class box : public drawable
{
public:
	//void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	bool isColliding(box &other);
	//virtual void update();
};

#endif