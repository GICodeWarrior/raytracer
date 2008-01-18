
#include "models/Sphere.h"
#include "models/Polygon.h"

#include "World.h"
#include "Camera.h"

#include <iostream>
#include <Magick++.h>

int main()
{
	World scene;
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
	/*
	points.clear();
	points.push_back(Point(-4.03571, 5.790754, 5.0));
	points.push_back(Point(-3.42891, 5.543348, 5.0));
	points.push_back(Point(-2.8396, 5.82991, 5.0));
	points.push_back(Point(-2.88739, 5.176363, 5.0));
	points.push_back(Point(-2.43274, 4.704445, 5.0));
	points.push_back(Point(-3.06907, 4.547937, 5.0));
	points.push_back(Point(-3.3774, 3.969714, 5.0));
	points.push_back(Point(-3.72288, 4.526534, 5.0));
	points.push_back(Point(-4.36808, 4.64109, 5.0));
	points.push_back(Point(-3.94528, 5.141731, 5.0));
	Polygon *star = new Polygon(points, Color(255, 255, 0));
	scene.add(star);
	*/
	
	Light light(Point(1, 45, 0), Color(255,255,255), &scene);
	scene.addLight(light);
	
	cout << "Constructed scene" << endl;
	
	Camera camera(&scene);
	
	cout << "Created camera" << endl;

	Magick::Image image(640, 480, "RGB", MagickLib::CharPixel, camera.getImage());
	
	cout << "Created Magick++ image" << endl;
	
	image.write("image.png");
	
	cout << "Success!!!" << endl;
	
	return 0;	
}
