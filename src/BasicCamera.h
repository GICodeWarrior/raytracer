#ifndef BASICCAMERA_H_
#define BASICCAMERA_H_

#include "../third-party/point.h"
#include "../third-party/vector.h"
#include "World.h"
#include "Camera.h"

struct Pixel;

class BasicCamera : public Camera
{
public:
	BasicCamera(const World *s, Point o, Point lookAt);
	BasicCamera(const World *s, Point o, Vector up, Vector right, Vector direction);
	virtual ~BasicCamera();
	virtual void getImage(int width, int height, Pixel *image) const;
private:
	const World *scene;
	
	Point origin;
	
	Vector up;
	Vector right;
	Vector direction;
};

#endif /*BASICCAMERA_H_*/
