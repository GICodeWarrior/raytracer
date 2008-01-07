#include "CompositeModel.h"
#include "../Intersection.h"

CompositeModel::CompositeModel()
{
}

CompositeModel::~CompositeModel()
{
}

void CompositeModel::add(Model* model)
{
	models.push_back(model);
}

Intersection CompositeModel::intersect(Ray& ray)
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
