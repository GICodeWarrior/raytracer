
#include "materials/Checker.h"
#include "materials/Onion.h"
#include "materials/Phong.h"
#include "materials/Quilt.h"
#include "materials/Reflection.h"

#include "models/Sphere.h"
#include "models/Polygon.h"

#include "World.h"
#include "Camera.h"

#include <iostream>
#include <Magick++.h>

int main()
{
	World scene;
	Material *material;
	Sphere *sphere1 = new Sphere(Point(0,3,-2), 1, Color(255, 0, 0));
	Sphere *sphere2 = new Sphere(Point(2,2,2), 1, Color(0, 0, 255));
	//material = new Phong(sphere1, &scene);
	//material = new Onion(sphere1);
	//material = new Quilt(sphere1);
	material = new Reflection(sphere1, &scene, 1.0);
	material = new Phong(material, &scene);
	scene.add(material);
	//material = new Phong(sphere2, &scene);
	//material = new Checker(sphere2);
	//material = new Quilt(material);
	material = new Reflection(sphere2, &scene, 1.0);
	material = new Phong(material, &scene);
	scene.add(material);
	
	vector<Point> points;
	points.push_back(Point(-4, 0, -2));
	points.push_back(Point(-4, 0, 50));
	points.push_back(Point(12, 0, 50));
	points.push_back(Point(12, 0, -2));
	Polygon *floor = new Polygon(points, Color(0, 255, 0));
	material = new Checker(floor);
	material = new Quilt(material);
	material = new Phong(material, &scene);
	material = new Reflection(material, &scene, 1.0);
	scene.add(material);
	
	points.clear();
	points.push_back(Point(-3.94528, 5.141731, 5.0));
	points.push_back(Point(-4.03571, 5.790754, 5.0));
	points.push_back(Point(-3.42891, 5.543348, 5.0));
	points.push_back(Point(-2.8396, 5.82991, 5.0));
	points.push_back(Point(-2.88739, 5.176363, 5.0));
	points.push_back(Point(-2.43274, 4.704445, 5.0));
	points.push_back(Point(-3.06907, 4.547937, 5.0));
	points.push_back(Point(-3.3774, 3.969714, 5.0));
	points.push_back(Point(-3.72288, 4.526534, 5.0));
	points.push_back(Point(-4.36808, 4.64109, 5.0));
	Polygon *star = new Polygon(points, Color(255, 255, 0));
	material = new Reflection(star, &scene, 1.0);
	material = new Phong(material, &scene);
	//material = new Phong(star, &scene);
	scene.add(material);
	
	//Light light1(Point(1, 45, 0), Color(255,255,255), &scene);
	//scene.addLight(light1);
	
	Light light2(Point(-2, 10, -6), Color(255,64,64), &scene);
	scene.addLight(light2);
	
	Light light3(Point(5, 5, 0), Color(64,255,64), &scene);
	scene.addLight(light3);
	
	Light light4(Point(-5, 2, 5), Color(64,64,255), &scene);
	scene.addLight(light4);
	
	cout << "Constructed scene" << endl;
	
	Camera camera(&scene);
	
	cout << "Created camera" << endl;

	Magick::Image image(640, 480, "RGB", MagickLib::CharPixel, camera.getImage());
	
	cout << "Created Magick++ image" << endl;
	
	image.write("image.png");
	
	cout << "Success!!!" << endl;
	
	return 0;	
}
