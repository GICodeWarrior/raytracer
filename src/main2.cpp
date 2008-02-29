/*
  This file is part of Rusty's Raytracer.

  Rusty's Raytracer is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version.

  Rusty's Raytracer is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  Rusty's Raytracer.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2008 Rusty Burchfield
*/

#include "World.h"
#include "Camera.h"

#include "../parser/SceneLexer.hpp"
#include "../parser/SceneParser.hpp"
#include "../parser/SceneTreeParser.hpp"

#include <iostream>
#include <fstream>

#include <Magick++.h>
#include <antlr/ASTFactory.hpp>

using namespace std;

int main()
{
	cout << "Rusty's Raytracer  Copyright (C) 2008  Rusty Burchfield" << endl;
    cout << "This program comes with ABSOLUTELY NO WARRANTY." << endl;
    cout << "This is free software, and you are welcome to redistribute it" << endl;
    cout << "under certain conditions; see COPYING for details." << endl << endl;
    
    ifstream fin("image.pov");
    
	antlr::ASTFactory my_factory;
	SceneLexer lexer(fin);
	SceneParser parser(lexer);
	SceneTreeParser treeParser;
	parser.initializeASTFactory(my_factory);
	parser.setASTFactory(&my_factory);
	treeParser.initializeASTFactory(my_factory);
	
	cout << "Building AST..." << endl;
	flush(cout);
	
	parser.scene();
	
	cout << "Complete" << endl;
	cout << "Parsing AST..." << endl;
	flush(cout);
	
	cout << "AST: " << parser.getAST()->toStringList() << endl;
	
	World *w = treeParser.scene(parser.getAST());
	
	cout << "Complete" << endl;
	cout << "Rendering image...";
	flush(cout);

	//---------- Rendering parameters
	// Output size
	int width = 1024;
	int height = 768;
	Pixel* buffer = new Pixel[width * height];
	
	// Actual rendering
	w->getCamera().getImage(width, height, buffer);
	
	cout << "Complete" << endl;
	cout << "Created Magick++ image...";
	flush(cout);
	
	// Create a Magick++
	Magick::Image image(width, height, "RGB", MagickLib::CharPixel, buffer);
	
	cout << "Complete" << endl;
	cout << "Writing output...";
	flush(cout);
	
	// Write the data to a png
	image.write("image.png");
	
	delete[] buffer;
	
	cout << "Complete!!!" << endl;
	
	return 0;
}
