#ifndef CAMERA_H_
#define CAMERA_H_

#include "World.h"

struct Pixel;

class Camera
{
public:
	Camera(const World *s);
	virtual ~Camera();
	Pixel* getImage() const;
private:
	const World *scene;
};

#endif /*CAMERA_H_*/
