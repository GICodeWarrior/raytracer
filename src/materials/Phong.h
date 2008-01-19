#ifndef PHONG_H_
#define PHONG_H_

#include "Material.h"

class World;

class Phong : public Material
{
public:
	Phong(PrimitiveModel *s, World *w);
	virtual ~Phong();
	virtual Color colorAt(const Point &p) const;
private:
	World *world;
};

#endif /*PHONG_H_*/
