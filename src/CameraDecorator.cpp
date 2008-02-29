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

#include "CameraDecorator.h"

CameraDecorator::CameraDecorator(Camera *c)
: camera(c)
{
}

CameraDecorator::~CameraDecorator()
{
	delete camera;
}

void CameraDecorator::getImage(int width, int height, Pixel *image) const
{
	camera->getImage(width, height, image);
}

void CameraDecorator::setScene(const World *s)
{
	camera->setScene(s);
}
