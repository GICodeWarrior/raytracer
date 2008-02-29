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

#ifndef LIGHT_H_
#define LIGHT_H_

#include "common.h"
#include "Color.h"
#include "../third-party/point.h"

class World;

class Light
{
public:
	Light();
	Light(Point p, Color c, World *w);
	virtual ~Light();
	bool intersects(const Point &p) const;
	void setOrigin(Point p) {origin = p;};
	void setTint(Color t) {tint = t;};
	void setScene(World *s) {world = s;};
	const Point& getOrigin() const;
	const Color& getTint() const;
private:
	Point origin;
	Color tint;
	World *world;
	DISALLOW_EVIL_CONSTRUCTORS(Light);
};

#endif /*LIGHT_H_*/
