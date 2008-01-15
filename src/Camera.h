#ifndef CAMERA_H_
#define CAMERA_H_

#include "World.h"

struct Pixel;

class Camera
{
public:
	Camera(World *s);
	virtual ~Camera();
	Pixel* getImage();
private:
	World *scene;
};

#endif /*CAMERA_H_*/
