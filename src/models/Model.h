#ifndef MODEL_H_
#define MODEL_H_

class Intersection;
class Ray;

class Model
{
public:
	Model();
	virtual ~Model();
	virtual Intersection intersect(Ray& ray) = 0;
};

#endif /*MODEL_H_*/
