#ifndef CAMERADECORATOR_H_
#define CAMERADECORATOR_H_

#include "Camera.h"

class CameraDecorator : public Camera
{
public:
	CameraDecorator(Camera *c);
	virtual ~CameraDecorator();
	virtual void getImage(int width, int height, Pixel *image) const;
private:
	Camera *camera;
};

#endif /*CAMERADECORATOR_H_*/
