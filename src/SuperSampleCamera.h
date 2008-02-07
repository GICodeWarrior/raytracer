#ifndef SUPERSAMPLECAMERA_H_
#define SUPERSAMPLECAMERA_H_

#include "BasicCamera.h"

class SuperSampleCamera : public BasicCamera
{
public:
	SuperSampleCamera(const World *s, Point o, Point lookAt, unsigned int sampless);
	SuperSampleCamera(const World *s, Point o, Vector u, Vector r, Vector d, unsigned int samples);
	virtual ~SuperSampleCamera();
	virtual void getImage(int width, int height, Pixel *image) const;
private:
	unsigned int samples;
};

#endif /*SUPERSAMPLECAMERA_H_*/
