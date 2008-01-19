#ifndef MODEL_H_
#define MODEL_H_

class Intersection;
class Ray;

class Model
{
public:
	Model();
	virtual ~Model();
	virtual Intersection intersect(const Ray& ray) const = 0;
};

#endif /*MODEL_H_*/
