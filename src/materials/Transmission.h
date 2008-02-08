#ifndef TRANSMISSION_H_
#define TRANSMISSION_H_

#include "Material.h"

class World;

class Transmission : public Material
{
public:
	Transmission(PrimitiveModel *s, World *w, double transmissiveness, double ior);
	virtual ~Transmission();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
private:
	World *world;
	double transmissiveness;
	double ior;
};

#endif /*TRANSMISSION_H_*/
