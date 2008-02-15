#ifndef REINHARDTONECAMERA_H_
#define REINHARDTONECAMERA_H_

#include "CameraDecorator.h"

class ReinhardToneCamera : public CameraDecorator
{
public:
	ReinhardToneCamera(Camera *c, double ldmax);
	virtual ~ReinhardToneCamera();
	virtual void getImage(int width, int height, Pixel *image) const;
private:
	double ldmax;
};

#endif /*REINHARDTONECAMERA_H_*/
