#ifndef ENTITY_H
#define ENTITY_H

#include "vector2d.h"
#include "global.h"

class entity
{
protected:
	int iSize;
	float fRotation;
	vector2d v2dPosition;
public:
	entity();

	int size();
	int setSize(int i);
	float rotation();
	vector2d position();
	
	// Nodes which are used for pathfinding and layout of levels.
	vector2d nodePosition();
	void setNodePosition(int x, int y);
	void setNodePosition(vector2d node);
	
	void setPosition(vector2d pos);
	void setPosition(float x, float y);
	void setRotation(float fRotate);

	//virtual void update() = 0;

};

#endif