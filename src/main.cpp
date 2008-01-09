
#include "models/Sphere.h"
#include "models/CompositeModel.h"

#include "Camera.h"

#include <iostream>
#include <Magick++.h>

int main()
{
	CompositeModel scene;
	Sphere *sphere = new Sphere(Point(0,3,-2), 1, Color(255, 0, 0));
	scene.add(sphere);
	
	cout << "Constructed scene" << endl;
	
	Camera camera(&scene);
	
	cout << "Created camera" << endl;

	Magick::Image image(640, 480, "RGB", MagickLib::CharPixel, camera.getImage());
	
	cout << "Created Magick++ image" << endl;
	
	image.write("image.png");
	
	cout << "Success!!!" << endl;
	
	return 0;	
}
