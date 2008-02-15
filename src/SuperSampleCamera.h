#ifndef SUPERSAMPLECAMERA_H_
#define SUPERSAMPLECAMERA_H_

#include "CameraDecorator.h"

class Pixel;

class SuperSampleCamera : public CameraDecorator
{
public:
	SuperSampleCamera(Camera *c, unsigned int samples);
	virtual ~SuperSampleCamera();
	virtual void getImage(int width, int height, Pixel *image) const;
private:
	unsigned int samples;
};

#endif /*SUPERSAMPLECAMERA_H_*/
