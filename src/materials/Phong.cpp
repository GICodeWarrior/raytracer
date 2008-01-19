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
			Vector color = c.asVector();
			
			Vector source = light->getOrigin() - p;
			source.normalize();
			
			Vector normal = getModel()->normalAt(p);
			normal.normalize();
			
			Vector reflection = p - light->getOrigin() + 2 * normal;
			reflection.normalize();
			
			Vector view = Point(0.0, 3.0, -6.0) - p;
			view.normalize();
			
			diffuse += color * (source * normal);
			specular += color * pow(min(reflection * view, 0.0), 1.0/40.0);
			
			//cout << "i: " << i << " diffuse: " << diffuse << " specular: " << specular;
			//cout << " color: " << color << " source: " << source << " normal: " << normal;
			//cout << " reflection: " << reflection << " view: " << view << endl;
		}
	}
	
	if (!isfinite(specular.x) || !isfinite(specular.y) || !isfinite(specular.z))
		specular = Vector(0,0,0);
	
	return(0.1 * c.asVector() + 0.6 * diffuse + 0.4 * specular);
}
