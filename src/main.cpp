
#include "models/Sphere.h"
#include "models/CompositeModel.h"

#include "Camera.h"

int main()
{
	CompositeModel scene;
	Sphere *sphere = new Sphere(Point(0,3,-2), 1, Color(255, 0, 0));
	scene.add(sphere);
	
	Camera camera(&scene);
	
	camera.getImage();
	
	return 0;	
}
