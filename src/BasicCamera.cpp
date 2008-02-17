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

#include "BasicCamera.h"

#include "World.h"
#include "Intersection.h"
#include "Color.h"
#include "Ray.h"

BasicCamera::BasicCamera(const World *s, Point o, Point lookAt)
: scene(s), origin(o)
{
	double width = 1.33;
	double height = 1.0;
	double distance = 1.0;
	
	direction = lookAt - origin;
	direction.normalize();
	direction *= distance;
	
	right = Vector(0.0, 1.0, 0.0) ^ direction;
	right.normalize();
	right *= width;
	
	up = right ^ direction;
	up.normalize();
	up *= -height;
}

BasicCamera::BasicCamera(const World *s, Point o, Vector u, Vector r, Vector d)
: scene(s), origin(o), up(u), right(r), direction(d)
{
}

BasicCamera::~BasicCamera()
{
}

void BasicCamera::getImage(int imageWidth, int imageHeight, Pixel *image) const
{	
	Point viewOrigin(origin + direction - (right / 2) + (up / 2));
	
	int MAX_DEPTH = 20;
	int progress = 0;
	
	for (int y = 0; y < imageHeight; ++y)
	{
		Vector verticalOffset(up * (y / (double)imageHeight));
		
		for (int x = 0; x < imageWidth; ++x)
		{
			Vector horizontalOffset(right * (x / (double)imageWidth));
			Point intersection(viewOrigin + horizontalOffset - verticalOffset);
			
			Vector castDirection(intersection - origin);
			castDirection.normalize();
			
			Intersection i = scene->intersect(Ray(origin, castDirection));
			image[y * imageWidth + x] = i.getColor(MAX_DEPTH).asPixel();
		}
		
		if (y * 10.0 / imageHeight >= progress)
		{
			cout << progress;
			flush(cout);
			++progress;
		}
	}
}
