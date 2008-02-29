#ifndef COLORMATERIAL_H_
#define COLORMATERIAL_H_

#include "Material.h"

class ColorMaterial : public Material
{
public:
	ColorMaterial(Color c);
	ColorMaterial(PrimitiveModel *s, Color c);
	virtual ~ColorMaterial();
	virtual Color colorAt(const Ray &r, const Point &p, int depth) const;
private:
	Color color;
};

#endif /*COLORMATERIAL_H_*/
