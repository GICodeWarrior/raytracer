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

#include "Phong.h"

#include <vector>
#include "../../third-party/vector.h"
#include "../Light.h"
#include "../World.h"

Phong::Phong(PrimitiveModel *s, World *w)
: Material(s), world(w), ka(0.2), kd(0.6), ks(1.0), ke(40)
{
}

Phong::Phong(PrimitiveModel *s, World *w, double ambient,
			 double diffuse, double specular, double exponent)
: Material(s), world(w), ka(ambient), kd(diffuse), ks(specular), ke(exponent)
{
}

Phong::~Phong()
{
}

Color Phong::colorAt(const Ray &r, const Point &p, int depth) const
{	
	Color c = Material::colorAt(r, p, depth);
	
	Vector diffuse(0,0,0);
	Vector specular(0,0,0);
	
	const vector<Light> *lights = world->getLights();
	const Light *light;
	
	for (unsigned int i = 0; i < lights->size(); ++i)
	{
		light = &lights->at(i);
		if (light->intersects(p))
		{
			Vector mc = c.asVector();
			Vector sc = Color::WHITE.asVector();
			Vector lc = light->getTint().asVector();
			Vector diffuseColor(mc.x * lc.x, mc.y * lc.y, mc.z * lc.z);
			Vector specularColor(sc.x * lc.x, sc.y * lc.y, sc.z * lc.z);
			
			Vector source = light->getOrigin() - p;
			source.normalize();
			
			Vector normal = getModel()->normalAt(p);
			normal.normalize();
			
			Vector incoming = p - light->getOrigin();
			incoming.normalize();
			
			Vector reflection = incoming - 2 * normal * (incoming * normal);
			reflection.normalize();
			
			Vector view = Point(0.0, 3.0, -6.0) - p;
			view.normalize();
			
			diffuse += diffuseColor * (source * normal);
			specular += specularColor * pow(max(reflection * view, 0.0), ke);
		}
	}
	
	return Color(ka * c.asVector() + kd * diffuse + ks * specular);
}
