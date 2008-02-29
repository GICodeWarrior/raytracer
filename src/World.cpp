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

#include "World.h"
#include "Camera.h"

#include "Intersection.h"

World::World()
{
}

World::~World()
{
	for(vector<const Light*>::const_iterator c = lights.begin();
		c != lights.end();
		++c)
	{
		delete *c;
	}
}

Intersection World::intersect(const Ray& ray) const
{
	Intersection i = CompositeModel::intersect(ray);
	i.setBackground(background);
	return i;
}

void World::addLight(Light *l)
{
	l->setScene(this);
	lights.push_back(l);
}

const vector<const Light*>* World::getLights() const
{
	cout << "lights:" << lights.size() << endl;
	return &lights;
}

void World::setBackground(Color c)
{
	background = c;	
}

void World::setCamera(Camera *c)
{
	camera = c;
	camera->setScene(this);
}
