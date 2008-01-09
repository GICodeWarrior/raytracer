#ifndef CAMERA_H_
#define CAMERA_H_

#include "models/Model.h"

struct Pixel;

class Camera
{
public:
	Camera(Model *s);
	virtual ~Camera();
	Pixel* getImage();
private:
	Model *scene;
};

#endif /*CAMERA_H_*/
