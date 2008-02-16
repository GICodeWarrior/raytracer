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

#include "CompositeModel.h"
#include "../Intersection.h"

CompositeModel::CompositeModel()
{
}

CompositeModel::~CompositeModel()
{
	for(unsigned int c = 0; c < models.size(); ++c)
	{
		delete models[c];
	}
}

void CompositeModel::add(Model* model)
{
	models.push_back(model);
}

Intersection CompositeModel::intersect(const Ray& ray) const
{
	Intersection nearest;
	
	for(unsigned int c = 0; c < models.size(); ++c)
	{
		Intersection next = models[c]->intersect(ray);
		if (nearest.compare(ray, next) < 0)
		{
			nearest = next;
		}
	}
	
	return nearest;
}
