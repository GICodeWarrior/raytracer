
#include "materials/Checker.h"
#include "materials/Onion.h"
#include "materials/Phong.h"
#include "materials/Quilt.h"
#include "materials/Reflection.h"
#include "materials/Transmission.h"

#include "models/Sphere.h"
#include "models/Polygon.h"

#include "World.h"
#include "CameraDecorator.h"
#include "WardToneCamera.h"
#include "ReinhardToneCamera.h"
#include "BasicCamera.h"
#include "SuperSampleCamera.h"

#include <iostream>
#include <Magick++.h>

int main()
{
	cout << "Constructing scene...";
	flush(cout);
	
	World scene;
	Material *material;
	//Sphere *sphere1 = new Sphere(Point(0,3,-2), 1, Color(255, 0, 0));
	Sphere *sphere1 = new Sphere(Point(0,3,-2), 1, Color::BLACK);
	//Sphere *sphere2 = new Sphere(Point(2,2,2), 1, Color(0, 0, 255));
	Sphere *sphere2 = new Sphere(Point(2,2,2), 1, Color::WHITE);
	material = new Phong(sphere1, &scene);
	//material = new Onion(sphere1);
	//material = new Quilt(sphere1);
	//material = new Reflection(sphere1, &scene, 1.0);
	material = new Transmission(material, &scene, 1.0, 1.01);
	//material = new Phong(material, &scene);
	scene.add(material);
	material = new Phong(sphere2, &scene);
	//material = new Checker(sphere2);
	//material = new Quilt(material);
	//material = new Phong(material, &scene);
	material = new Reflection(material, &scene, 0.1);
	scene.add(material);
	
	vector<Point> points;
	points.push_back(Point(-4, 0, -2));
	points.push_back(Point(-4, 0, 50));
	points.push_back(Point(12, 0, 50));
	points.push_back(Point(12, 0, -2));
	Polygon *floor = new Polygon(points, Color(0, 255, 0));
	material = new Checker(floor);
	//material = new Quilt(material);
	material = new Phong(material, &scene);
	//material = new Reflection(material, &scene, 0.5);
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
	//material = new Reflection(star, &scene, 1.0);
	//material = new Phong(material, &scene);
	material = new Phong(star, &scene);
	//scene.add(material);
	
	Light light1(Point(1, 45, 0), Color(255,255,255), &scene);
	scene.addLight(light1);
	
	Light light2(Point(-2, 10, -6), Color(255,64,64), &scene);
	//scene.addLight(light2);
	
	Light light3(Point(5, 5, 0), Color(64,255,64), &scene);
	//scene.addLight(light3);
	
	Light light4(Point(-5, 2, 5), Color(64,64,255), &scene);
	//scene.addLight(light4);
	
	cout << "Complete" << endl;
	cout << "Creating camera...";
	flush(cout);
	
	Point origin(0.0, 3.0, -6.0);
	Point lookAt(0.0, 3.0, 5.0);
	Camera *camera = new BasicCamera(&scene, origin, lookAt);
	//camera = new WardToneCamera(camera, 1);
	camera = new ReinhardToneCamera(camera, 1);
	camera = new SuperSampleCamera(camera, 4);
	
	cout << "Complete" << endl;
	cout << "Rendering image...";
	flush(cout);

	int width = 640;
	int height = 480;
	//width = 1024;
	//height = 768;
	Pixel* buffer = new Pixel[width * height];
	
	camera->getImage(width, height, buffer);
	delete camera;
	
	cout << "Complete" << endl;
	cout << "Created Magick++ image...";
	flush(cout);
	
	Magick::Image image(width, height, "RGB", MagickLib::CharPixel, buffer);
	
	cout << "Complete" << endl;
	cout << "Writing output...";
	flush(cout);
	
	image.write("image.png");
	
	delete[] buffer;
	
	cout << "Complete!!!" << endl;
	
	return 0;	
}
