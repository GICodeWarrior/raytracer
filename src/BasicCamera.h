/*
  This file is part of Rusty's Raytracer.

  Rusty's Raytracer is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version.

  Rusty's Raytracer is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  Rusty's Raytracer.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2008 Rusty Burchfield
*/

#ifndef BASICCAMERA_H_
#define BASICCAMERA_H_

#include "Camera.h"
#include "common.h"

#include "../third-party/point.h"
#include "../third-party/vector.h"

struct Pixel;
class World;

class BasicCamera : public Camera
{
public:
	BasicCamera();
	BasicCamera(const World *s, Point o, Point lookAt);
	BasicCamera(const World *s, Point o, Vector up, Vector right, Vector direction);
	virtual ~BasicCamera();
	virtual void getImage(int width, int height, Pixel *image) const;
	virtual void setScene(const World *s);
	void setLook(Point lookAt);
	void setOrigin(Point p) {origin = p;};
	void setUp(Vector v) {up = v;};
	void setRight(Vector v) {right = v;};
	void setDirection(Vector v) {direction = v;};
private:
	void updateVectors(Point lookAt);

	const World *scene;
	
	Point origin;
	
	Vector up;
	Vector right;
	Vector direction;
	
	DISALLOW_EVIL_CONSTRUCTORS(BasicCamera);
};

#endif /*BASICCAMERA_H_*/
