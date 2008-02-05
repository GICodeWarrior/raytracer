#ifndef CAMERA_H_
#define CAMERA_H_

struct Pixel;

class Camera
{
public:
	Camera();
	virtual ~Camera();
	virtual void getImage(int width, int height, Pixel *image) const = 0;
};

#endif /*CAMERA_H_*/
