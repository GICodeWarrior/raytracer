#include "Phong.h"

#include <vector>
#include "../../third-party/vector.h"
#include "../Light.h"
#include "../World.h"

Phong::Phong(PrimitiveModel *s, World *w)
: Material(s), world(w)
{
}

Phong::~Phong()
{
}

Color Phong::colorAt(const Point &p) const
{	
	Color c = Material::colorAt(p);
	if (c == Color::BLACK) return c;
	
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
			specular += specularColor * pow(max(reflection * view, 0.0), 40.0);
		}
	}
	
	return(0.1 * c.asVector() + 0.6 * diffuse + 1 * specular);
}
