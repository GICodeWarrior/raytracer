
#include "models/Sphere.h"
#include "models/Plane.h"
#include "models/CompositeModel.h"

#include "Camera.h"

#include <iostream>
#include <Magick++.h>

int main()
{
	CompositeModel scene;
	Sphere *sphere1 = new Sphere(Point(0,3,-2), 1, Color(255, 0, 0));
	Sphere *sphere2 = new Sphere(Point(2,2,2), 1, Color(0, 0, 255));
	scene.add(sphere1);
	scene.add(sphere2);
	
	Plane *plane = new Plane(Vector(0,1,0), 0, Color(0, 255, 0));
	scene.add(plane);
	
	cout << "Constructed scene" << endl;
	
	Camera camera(&scene);
	
	cout << "Created camera" << endl;

	Magick::Image image(640, 480, "RGB", MagickLib::CharPixel, camera.getImage());
	
	cout << "Created Magick++ image" << endl;
	
	image.write("image.png");
	
	cout << "Success!!!" << endl;
	
	return 0;	
}
