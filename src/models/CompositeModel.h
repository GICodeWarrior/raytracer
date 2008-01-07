#ifndef COMPOSITEMODEL_H_
#define COMPOSITEMODEL_H_

#include <vector>
#include "Model.h"

class CompositeModel : public Model
{
public:
	CompositeModel();
	virtual ~CompositeModel();
	
	void add(Model* model);
	Intersection intersect(Ray& ray);
	
private:
	std::vector<Model*> models;
};

#endif /*COMPOSITEMODEL_H_*/
