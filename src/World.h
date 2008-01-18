#ifndef WORLD_H_
#define WORLD_H_

#include "models/CompositeModel.h"

#include "Light.h"

class World : public CompositeModel
{
public:
	World();
	virtual ~World();
	void addLight(Light l);
	const vector<Light>* getLights() const;
private:
	vector<Light> lights;
};

#endif /*WORLD_H_*/
