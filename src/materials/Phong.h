#ifndef PHONG_H_
#define PHONG_H_

#include "Material.h"

class World;

class Phong : public Material
{
public:
	Phong(PrimitiveModel *s, World *w);
	Phong(PrimitiveModel *s, World *w, double ambient,
		  double diffuse, double specular, double exponent);
	virtual ~Phong();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
private:
	World *world;
	double ka, kd, ks, ke;
};

#endif /*PHONG_H_*/
