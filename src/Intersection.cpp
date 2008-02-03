#include "Intersection.h"
#include "Ray.h"

#include "models/PrimitiveModel.h"

Intersection::Intersection()
: model(NULL), ray(Point(), Vector())
{
}

Intersection::Intersection(const PrimitiveModel *m, Ray r, Point p)
: model(m), ray(r), point(p)
{
}

Intersection::~Intersection()
{
}

int Intersection::compare(const Ray &ray, const Intersection &i) const
{
	if (!model) return -1;
	if (!i.model) return 1;
	Point start = ray.getOrigin();
	double d1 = point.d2(start);
	double d2 = i.point.d2(start);
	
	if (d1 < d2) return 1;
	if (d1 > d2) return -1;
	return 0;
}

Color Intersection::getColor() const
{
	if (model)
	{
		return model->colorAt(ray, point);
	}
	
	return Color(0,0,0);
}

Point Intersection::getPoint() const
{
	return point;
}

const PrimitiveModel* Intersection::getModel() const
{
	return model;
}
