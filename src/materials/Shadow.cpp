#include "Shadow.h"

Shadow::Shadow(PrimitiveModel *s, World *w)
: Material(s), world(w)
{
}

Shadow::~Shadow()
{
}

Color Shadow::colorAt(const Point &p) const
{	
	Color c = Material::colorAt(p);
	
	const vector<Light> *lights = world->getLights();
	
	bool visible = false;
	
	for (unsigned int i = 0; i < lights->size(); ++i)
	{
		visible |= lights->at(i).intersects(p);
	}
	
	return visible ? c : Color(0,0,0);
}
