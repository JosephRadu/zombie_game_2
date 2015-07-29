#include "camera.h"

Camera::Camera()
{
	v2dPosition.set(0,0);
	fZoom = 1;
	iZoomAmount = 0;
	iXPanAmount = 0;
	iYPanAmount = 0;
}

void Camera::setX(float x)
{
	v2dPosition.setX(x);
}
void Camera::setY(float y)
{
	v2dPosition.setY(y);
}
void Camera::setPosition(vector2d v2dPos)
{
	v2dPosition.set(v2dPos);
}

void Camera::setPosition(float x, float y)
{
	v2dPosition.set(x,y);
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

void Camera::update()
{
	if (fZoom != 1)
	{
		if (fZoom < 1)
		{
			fZoom = fZoom + 0.0005;
		}
		else if (fZoom > 1)
		{
			fZoom = fZoom - 0.0005;
		}

	}

	if (fZoom < 1.001 && fZoom > 0.999)
	{
		fZoom = 1;
	}

	else if (fZoom > 1.1)
	{
		fZoom = 1.1;
	}

	else if (fZoom < 0.9)
	{
		fZoom = 0.9;
	}


	//fZoom = ceil(fZoom,);
}

int Camera::xPanAmount()
{
	if (iXPanAmount != 0)
	{
		if (iXPanAmount < 0)
		{
			iXPanAmount++; 
			return -1;
		}

		if (iXPanAmount > 0)
		{
			iXPanAmount--; 
			return 1;
		}

	}
	else
	{
		return 0;
	}


}

int Camera::yPanAmount()
{
	if (iYPanAmount != 0)
	{
		if (iYPanAmount < 0)
		{
			iYPanAmount++; 
			return -1;
		}

		if (iYPanAmount > 0)
		{
			iYPanAmount--; 
			return 1;
		}

	}
	else
	{
		return 0;
	}

}

void Camera::setXPanAmount(int i)
{
	iXPanAmount = i;
}
void Camera::setYPanAmount(int i)
{
	iYPanAmount = i;
}

int Camera::cameraSpeed()
{
	return iCameraSpeed;
}

void Camera::setZoomAmount(int iZoom)
{
	iZoomAmount = iZoom;
}
int Camera::zoomAmount()
{
	return iZoomAmount;
}