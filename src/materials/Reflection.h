#ifndef REFLECTION_H_
#define REFLECTION_H_

#include "Material.h"

class World;

class Reflection : public Material
{
public:
	Reflection(PrimitiveModel *s, World *w, double reflectivity);
	virtual ~Reflection();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
private:
	World *world;
	double reflectivity;
};

#endif /*REFLECTION_H_*/
