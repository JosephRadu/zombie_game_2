#ifndef BREAKABLE_H
#define BREAKABLE_H

#include "wall.h"

class Breakable : public Wall
{
protected:
	int iHealth;
	int iMaxHealth;
public:
	Breakable();
	Breakable(int nodeX, int nodeY);

	int health();
	int maxHealth();

	void setHealth(int i);


};

#endif