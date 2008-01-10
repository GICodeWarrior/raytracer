
#include "models/Sphere.h"
#include "models/Polygon.h"
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
	
	vector<Point> points;
	points.push_back(Point(-4, 0, -2));
	points.push_back(Point(-4, 0, 50));
	points.push_back(Point(12, 0, 50));
	points.push_back(Point(12, 0, -2));
	Polygon *floor = new Polygon(points, Color(0, 255, 0));
	scene.add(floor);
	
	cout << "Constructed scene" << endl;
	
	Camera camera(&scene);
	
	cout << "Created camera" << endl;

	Magick::Image image(640, 480, "RGB", MagickLib::CharPixel, camera.getImage());
	
	cout << "Created Magick++ image" << endl;
	
	image.write("image.png");
	
	cout << "Success!!!" << endl;
	
	return 0;	
}
