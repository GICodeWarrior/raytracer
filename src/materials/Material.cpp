#include "Material.h"

#include "../Intersection.h"

Material::Material(PrimitiveModel *s)
: subModel(s)
{
}

Material::~Material()
{
	delete subModel;
}

Color Material::colorAt(const Point &p) const
{
	return subModel->colorAt(p);
}

Intersection Material::intersect(const Ray& ray) const
{
	Intersection i = subModel->intersect(ray);
	if (i.getModel())
	{
		i = Intersection(this, i.getPoint());
	}
	return i;
}
