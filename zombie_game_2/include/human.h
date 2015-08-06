#ifndef HUMAN_H
#define HUMAN_H

#include "breakable.h"

class Human : public Breakable
{
private:

public:
	Human();
	Human(int nodeX, int nodeY);
};

#endif