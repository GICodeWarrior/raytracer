#ifndef WARDTONECAMERA_H_
#define WARDTONECAMERA_H_

#include "CameraDecorator.h"

class WardToneCamera : public CameraDecorator
{
public:
	WardToneCamera(Camera *c, double ldmax);
	virtual ~WardToneCamera();
	virtual void getImage(int width, int height, Pixel *image) const;
private:
	double ldmax;
};

#endif /*WARDTONECAMERA_H_*/
