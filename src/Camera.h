#ifndef CAMERA_H_
#define CAMERA_H_

#include "../third-party/point.h"
#include "../third-party/vector.h"
#include "World.h"

struct Pixel;

class Camera
{
public:
	Camera(const World *s, Point o, Vector lookAt);
	virtual ~Camera();
	Pixel* getImage(int width, int height, Pixel *image) const;
private:
	const World *scene;
	
	Point origin;
	
	Vector up;
	Vector right;
	Vector direction;
};

#endif /*CAMERA_H_*/
