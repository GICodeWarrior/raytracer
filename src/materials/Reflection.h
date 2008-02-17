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

#ifndef REFLECTION_H_
#define REFLECTION_H_

#include "../common.h"
#include "Material.h"

class World;

class Reflection : public Material
{
public:
	Reflection(PrimitiveModel *s, World *w, double reflectivity);
	virtual ~Reflection();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
private:
	World *world;
	double reflectivity;
	DISALLOW_EVIL_CONSTRUCTORS(Reflection);
};

#endif /*REFLECTION_H_*/
