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

#include "WardToneCamera.h"

#include <math.h>

#include "../third-party/vector.h"
#include "Color.h"

WardToneCamera::WardToneCamera(Camera *c, double m)
: CameraDecorator(c), ldmax(m)
{
}

WardToneCamera::~WardToneCamera()
{
}

void WardToneCamera::getImage(int width, int height, Pixel *image) const
{
	Vector colorSpace(0.27, 0.67, 0.06);
	
	CameraDecorator::getImage(width, height, image);
	
	double logSum = 0;
	
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Vector color = Color(image[y * width + x]).asVector() * ldmax;
			double ltotal = color * colorSpace;
			
			logSum += log10(ltotal + 1e-10);
		}
	}
	
	double key = exp(logSum / (width * height));
	double sf = pow((1.219 + pow(ldmax / 2, 0.4)) / (1.219 + pow(key, 0.4)), 2.5);
	
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Vector color = Color(image[y * width + x]).asVector() * ldmax;
			
			color *= sf;
			color /= ldmax;
			
			// Rescale the vector so the Vector->Color conversion doesn't threshold
			double maxComponent = max(max(color.x, color.y), color.z);
			if (maxComponent > 1.0) color /= maxComponent;
	
			image[y * width + x] = Color(color).asPixel();
		}
	}
}
