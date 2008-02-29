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

#include "Material.h"

#include "../../third-party/vector.h"
#include "../Intersection.h"

Material::Material()
: subModel(NULL)
{
}

Material::Material(PrimitiveModel *s)
: subModel(s)
{
}

Material::~Material()
{
	delete subModel;
}

Intersection Material::intersect(const Ray& ray) const
{
	Intersection i = subModel->intersect(ray);
	if (i.getModel()) i.setSource(this);  // Update source to us
	return i;
}

Color Material::colorAt(const Ray &r, const Point &p, int depth) const
{
	return subModel->colorAt(r, p, depth);
}

Vector Material::normalAt(const Point &p) const
{
	return subModel->normalAt(p);
}

void Material::bind(PrimitiveModel *s)
{
	subModel = s;
}

PrimitiveModel* Material::getModel() const
{
	return subModel;	
}
