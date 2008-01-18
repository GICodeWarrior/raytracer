#include "Shadow.h"

Shadow::Shadow(PrimitiveModel *s, World *w)
: Material(s), world(w)
{
}

Shadow::~Shadow()
{
}

Color Shadow::colorAt(Point &p)
{
	Color c = Material::colorAt(p);
	
	const vector<Light> *lights = world->getLights();
	
	for (unsigned int c = 0; c < lights->size(); ++c)
	{
		lights->at(c).intersects(p);
	}
	
	return c;
}
