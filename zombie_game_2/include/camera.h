#ifndef CAMERA_H
#define CAMERA_H

#include <stdio.h>
#include <math.h>   

#include "vector2d.h"

class Camera
{
private:
	vector2d v2dPosition;
	float fZoom;
	static const int iCameraSpeed = 30;
	int iZoomAmount;
	int iXPanAmount;

	int iYPanAmount;
public:
	Camera();

	void update();

	int cameraSpeed();
	void setX(float x);
	void setY(float y);
	void setPosition(vector2d v2dPos);
	void setPosition(float x, float y);
	void setZoom(float fZoomIn);

	void setZoomAmount(int iZoom);
	int zoomAmount();

	void setXPanAmount(int i);
	void setYPanAmount(int i);

	int xPanAmount();
	int yPanAmount();

	vector2d position();
	float zoom();

};

#endif