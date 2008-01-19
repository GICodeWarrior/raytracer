#include "CompositeModel.h"
#include "../Intersection.h"

CompositeModel::CompositeModel()
{
}

CompositeModel::~CompositeModel()
{
	for(unsigned int c = 0; c < models.size(); ++c)
	{
		delete models[c];
	}
}

void CompositeModel::add(Model* model)
{
	models.push_back(model);
}

Intersection CompositeModel::intersect(const Ray& ray) const
{
	Intersection nearest;
	
	for(unsigned int c = 0; c < models.size(); ++c)
	{
		Intersection next = models[c]->intersect(ray);
		if (nearest.compare(ray, next) < 0)
		{
			nearest = next;
		}
	}
	
	return nearest;
}
