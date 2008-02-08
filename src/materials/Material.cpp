#include "Material.h"

#include "../../third-party/vector.h"
#include "../Intersection.h"

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
	if (i.getModel())
	{
		i = Intersection(this, ray, i.getPoint());
	}
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

PrimitiveModel* Material::getModel() const
{
	return subModel;	
}
