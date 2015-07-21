#ifndef WALL_H
#define WALL_H

#include "box.h"

class Wall : public box
{
public:
	Wall();
	Wall(int nodeX, int nodeY);


};

#endif