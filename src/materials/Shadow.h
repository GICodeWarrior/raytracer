#ifndef SHADOW_H_
#define SHADOW_H_

#include "Material.h"
#include "../World.h"

class Shadow : public Material
{
public:
	Shadow(PrimitiveModel *s, World *w);
	virtual ~Shadow();
	virtual Color colorAt(const Ray &r, const Point &p) const;
private:
	World *world;
};

#endif /*SHADOW_H_*/
