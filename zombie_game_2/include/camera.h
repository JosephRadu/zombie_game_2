#ifndef CAMERA_H
#define CAMERA_H

#include "vector2d.h"

class Camera
{
private:
	vector2d v2dPosition;
	float fZoom;
public:
	Camera();

	void setX(float x);
	void setY(float y);
	void setPosition(vector2d v2dPos);
	void setZoom(float fZoomIn);

	vector2d position();
	float zoom();

};

#endif