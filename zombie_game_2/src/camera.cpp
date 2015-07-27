#include "camera.h"

Camera::Camera()
{
	v2dPosition.set(0,0);
	float fZoom = 1;
}

void Camera::setX(float x)
{
	v2dPosition.setY(x);
}
void Camera::setY(float y)
{
	v2dPosition.setY(y);
}
void Camera::setPosition(vector2d v2dPos)
{
	v2dPosition.set(v2dPos);
}
void Camera::setZoom(float fZoomIn)
{
	fZoom = fZoomIn;
}

vector2d Camera::position()
{
	return v2dPosition;
}
float Camera::zoom()
{
	return fZoom;
}