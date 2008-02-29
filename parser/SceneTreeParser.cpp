/* $ANTLR 2.7.6 (20070910): "pov.g" -> "SceneTreeParser.cpp"$ */
#include "SceneTreeParser.hpp"
#include <antlr/Token.hpp>
#include <antlr/AST.hpp>
#include <antlr/NoViableAltException.hpp>
#include <antlr/MismatchedTokenException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/BitSet.hpp>
#line 147 "pov.g"

#include "../src/materials/Phong.h"
#include "../src/materials/Reflection.h"
#include "../src/materials/Transmission.h"
#include "../src/materials/ColorMaterial.h"

#include "../src/models/Sphere.h"
#include "../src/models/Polygon.h"
#include "../src/models/Plane.h"

#include "../src/World.h"
#include "../src/Light.h"
#include "../src/Color.h"
#include "../src/BasicCamera.h"

#include <math.h>
#include <sstream>

#line 29 "SceneTreeParser.cpp"
SceneTreeParser::SceneTreeParser()
	: ANTLR_USE_NAMESPACE(antlr)TreeParser() {
}

World * SceneTreeParser::scene(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"scene",_t);
#line 168 "pov.g"
	World *w;
#line 38 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST scene_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 168 "pov.g"
	
	w = new World();
	Camera *cam;
	Color c;
	Light *l;
	Model *model;
	
#line 48 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t79 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp54_AST_in = _t;
		match(_t,SCENE);
		_t = _t->getFirstChild();
		{ // ( ... )+
		int _cnt81=0;
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == CAMERA)) {
				cam=camera(_t);
				_t = _retTree;
#line 175 "pov.g"
				w->setCamera(cam);
#line 65 "SceneTreeParser.cpp"
			}
			else {
				if ( _cnt81>=1 ) { goto _loop81; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);}
			}
			
			_cnt81++;
		}
		_loop81:;
		}  // ( ... )+
		{ // ( ... )+
		int _cnt83=0;
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == BACKGROUND)) {
				c=background(_t);
				_t = _retTree;
#line 176 "pov.g"
				w->setBackground(c);
#line 85 "SceneTreeParser.cpp"
			}
			else {
				if ( _cnt83>=1 ) { goto _loop83; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);}
			}
			
			_cnt83++;
		}
		_loop83:;
		}  // ( ... )+
		{ // ( ... )+
		int _cnt85=0;
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == LIGHT)) {
				l=light(_t);
				_t = _retTree;
#line 177 "pov.g"
				w->addLight(l);
#line 105 "SceneTreeParser.cpp"
			}
			else {
				if ( _cnt85>=1 ) { goto _loop85; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);}
			}
			
			_cnt85++;
		}
		_loop85:;
		}  // ( ... )+
		{
		model=object(_t);
		_t = _retTree;
#line 178 "pov.g"
		w->add(model);
#line 120 "SceneTreeParser.cpp"
		}
		_t = __t79;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return w;
}

BasicCamera * SceneTreeParser::camera(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"camera",_t);
#line 181 "pov.g"
	BasicCamera *c;
#line 138 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST camera_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 181 "pov.g"
	
	c = new BasicCamera();
	Point p;
	Vector v;
	
#line 146 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t88 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp55_AST_in = _t;
		match(_t,CAMERA);
		_t = _t->getFirstChild();
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == LOCATION)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t90 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp56_AST_in = _t;
				match(_t,LOCATION);
				_t = _t->getFirstChild();
				p=point(_t);
				_t = _retTree;
#line 186 "pov.g"
				c->setOrigin(p);
#line 166 "SceneTreeParser.cpp"
				_t = __t90;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop91;
			}
			
		}
		_loop91:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == RIGHT)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t93 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp57_AST_in = _t;
				match(_t,RIGHT);
				_t = _t->getFirstChild();
				v=vector(_t);
				_t = _retTree;
#line 187 "pov.g"
				c->setRight(v);
#line 190 "SceneTreeParser.cpp"
				_t = __t93;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop94;
			}
			
		}
		_loop94:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == UP)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t96 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp58_AST_in = _t;
				match(_t,UP);
				_t = _t->getFirstChild();
				v=vector(_t);
				_t = _retTree;
#line 188 "pov.g"
				c->setUp(v);
#line 214 "SceneTreeParser.cpp"
				_t = __t96;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop97;
			}
			
		}
		_loop97:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == DIRECTION)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t99 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp59_AST_in = _t;
				match(_t,DIRECTION);
				_t = _t->getFirstChild();
				v=vector(_t);
				_t = _retTree;
#line 189 "pov.g"
				c->setDirection(v);
#line 238 "SceneTreeParser.cpp"
				_t = __t99;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop100;
			}
			
		}
		_loop100:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == LOOK_AT)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t102 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp60_AST_in = _t;
				match(_t,LOOK_AT);
				_t = _t->getFirstChild();
				v=vector(_t);
				_t = _retTree;
#line 190 "pov.g"
				c->setLook(v);
#line 262 "SceneTreeParser.cpp"
				_t = __t102;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop103;
			}
			
		}
		_loop103:;
		} // ( ... )*
		_t = __t88;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return c;
}

Color  SceneTreeParser::background(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"background",_t);
#line 193 "pov.g"
	Color c;
#line 289 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST background_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t105 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp61_AST_in = _t;
		match(_t,BACKGROUND);
		_t = _t->getFirstChild();
		c=color(_t);
		_t = _retTree;
		_t = __t105;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return c;
}

Light * SceneTreeParser::light(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"light",_t);
#line 196 "pov.g"
	Light *l;
#line 315 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST light_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 196 "pov.g"
	
	l = new Light();
	Point p;
	Color c;
	
#line 323 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t107 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp62_AST_in = _t;
		match(_t,LIGHT);
		_t = _t->getFirstChild();
		p=point(_t);
		_t = _retTree;
		c=color(_t);
		_t = _retTree;
		_t = __t107;
		_t = _t->getNextSibling();
#line 201 "pov.g"
		
		l->setOrigin(p);
		l->setTint(c);
		
#line 341 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return l;
}

Model * SceneTreeParser::object(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"object",_t);
#line 207 "pov.g"
	Model *m;
#line 356 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST object_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t109 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp63_AST_in = _t;
		match(_t,OBJECT);
		_t = _t->getFirstChild();
		{
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case SPHERE:
		{
			m=sphere(_t);
			_t = _retTree;
			break;
		}
		case POLYGON:
		{
			m=polygon(_t);
			_t = _retTree;
			break;
		}
		case PLANE:
		{
			m=plane(_t);
			_t = _retTree;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}
		}
		_t = __t109;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return m;
}

Point  SceneTreeParser::point(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"point",_t);
#line 274 "pov.g"
	Point p;
#line 408 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST point_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 274 "pov.g"
	
	double x,y,z;
	
#line 414 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t145 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp64_AST_in = _t;
		match(_t,POINT);
		_t = _t->getFirstChild();
		x=number(_t);
		_t = _retTree;
		y=number(_t);
		_t = _retTree;
		z=number(_t);
		_t = _retTree;
		_t = __t145;
		_t = _t->getNextSibling();
#line 277 "pov.g"
		
		p = Point(x,y,z);
		
#line 433 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return p;
}

Vector  SceneTreeParser::vector(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"vector",_t);
#line 281 "pov.g"
	Vector v;
#line 448 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST vector_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 281 "pov.g"
	
	Point p;
	
#line 454 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t147 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp65_AST_in = _t;
		match(_t,VECTOR);
		_t = _t->getFirstChild();
		p=point(_t);
		_t = _retTree;
		_t = __t147;
		_t = _t->getNextSibling();
#line 284 "pov.g"
		
		v = Vector(p.x, p.y, p.z);
		
#line 469 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return v;
}

Color  SceneTreeParser::color(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"color",_t);
#line 262 "pov.g"
	Color c;
#line 484 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST color_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 262 "pov.g"
	
	Vector v;
	
#line 490 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t141 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp66_AST_in = _t;
		match(_t,COLOR);
		_t = _t->getFirstChild();
		v=color_body(_t);
		_t = _retTree;
		_t = __t141;
		_t = _t->getNextSibling();
#line 265 "pov.g"
		
		c = Color(v);
		
#line 505 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return c;
}

PrimitiveModel * SceneTreeParser::sphere(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"sphere",_t);
#line 209 "pov.g"
	PrimitiveModel *model;
#line 520 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST sphere_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 209 "pov.g"
	
	Material *m;
	Point center;
	double radius;
	
#line 528 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t112 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp67_AST_in = _t;
		match(_t,SPHERE);
		_t = _t->getFirstChild();
		center=point(_t);
		_t = _retTree;
		radius=number(_t);
		_t = _retTree;
#line 214 "pov.g"
		
		model = new Sphere(center, radius, Color::WHITE);
		
#line 543 "SceneTreeParser.cpp"
		_t = __t112;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return model;
}

Polygon * SceneTreeParser::polygon(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"polygon",_t);
#line 218 "pov.g"
	Polygon *poly;
#line 560 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST polygon_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 218 "pov.g"
	
	poly = new Polygon();
	Point p;
	
#line 567 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t114 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp68_AST_in = _t;
		match(_t,POLYGON);
		_t = _t->getFirstChild();
		{ // ( ... )+
		int _cnt116=0;
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == POINT)) {
				p=point(_t);
				_t = _retTree;
#line 222 "pov.g"
				poly->addVertex(p);
#line 584 "SceneTreeParser.cpp"
			}
			else {
				if ( _cnt116>=1 ) { goto _loop116; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);}
			}
			
			_cnt116++;
		}
		_loop116:;
		}  // ( ... )+
		_t = __t114;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return poly;
}

Plane * SceneTreeParser::plane(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"plane",_t);
#line 224 "pov.g"
	Plane *p;
#line 610 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST plane_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 224 "pov.g"
	
	Vector n;
	double d;
	
#line 617 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t118 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp69_AST_in = _t;
		match(_t,PLANE);
		_t = _t->getFirstChild();
		n=vector(_t);
		_t = _retTree;
		d=number(_t);
		_t = _retTree;
		_t = __t118;
		_t = _t->getNextSibling();
#line 228 "pov.g"
		
		p = new Plane(n, d, Color::WHITE);
		
#line 634 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return p;
}

double  SceneTreeParser::number(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"number",_t);
#line 288 "pov.g"
	double d;
#line 649 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST number_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST i1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST i2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t149 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp70_AST_in = _t;
		match(_t,NUMBER);
		_t = _t->getFirstChild();
		i1 = _t;
		match(_t,INTEGER);
		_t = _t->getNextSibling();
		i2 = _t;
		match(_t,INTEGER);
		_t = _t->getNextSibling();
		_t = __t149;
		_t = _t->getNextSibling();
#line 289 "pov.g"
		
			stringstream s;
			s << i1->getText().c_str() << "." << i2->getText().c_str();
		d = atof(s.str().c_str());
		
#line 673 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return d;
}

Material * SceneTreeParser::object_modifier(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"object_modifier",_t);
#line 233 "pov.g"
	Material *m;
#line 688 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST object_modifier_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t120 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp71_AST_in = _t;
		match(_t,OBJECT_MOD);
		_t = _t->getFirstChild();
		{
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case INTERIOR:
		{
			m=interior(_t);
			_t = _retTree;
			break;
		}
		case PIGMENT:
		{
			m=pigment(_t);
			_t = _retTree;
			break;
		}
		case FINISH:
		{
			m=finish(_t);
			_t = _retTree;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}
		}
		_t = __t120;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return m;
}

Transmission * SceneTreeParser::interior(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"interior",_t);
#line 236 "pov.g"
	Transmission *t;
#line 740 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST interior_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 236 "pov.g"
	
	double ior;
	
#line 746 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t123 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp72_AST_in = _t;
		match(_t,INTERIOR);
		_t = _t->getFirstChild();
		ior=number(_t);
		_t = _retTree;
		_t = __t123;
		_t = _t->getNextSibling();
#line 239 "pov.g"
		
		t = new Transmission(1.0, ior);
		
#line 761 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return t;
}

Material * SceneTreeParser::pigment(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"pigment",_t);
#line 243 "pov.g"
	Material *m;
#line 776 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST pigment_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 243 "pov.g"
	
	Color c;
	
#line 782 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t125 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp73_AST_in = _t;
		match(_t,PIGMENT);
		_t = _t->getFirstChild();
		c=color(_t);
		_t = _retTree;
		_t = __t125;
		_t = _t->getNextSibling();
#line 246 "pov.g"
		
		m = new ColorMaterial(c);
		
#line 797 "SceneTreeParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return m;
}

Phong * SceneTreeParser::finish(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"finish",_t);
#line 250 "pov.g"
	Phong *p;
#line 812 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST finish_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 250 "pov.g"
	
	p = new Phong();
	Color c;
	double d;
	
#line 820 "SceneTreeParser.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t127 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp74_AST_in = _t;
		match(_t,FINISH);
		_t = _t->getFirstChild();
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == AMBIENT)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t129 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp75_AST_in = _t;
				match(_t,AMBIENT);
				_t = _t->getFirstChild();
				d=number(_t);
				_t = _retTree;
#line 255 "pov.g"
				p->setAmbient(d);
#line 840 "SceneTreeParser.cpp"
				_t = __t129;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop130;
			}
			
		}
		_loop130:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == DIFFUSE)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t132 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp76_AST_in = _t;
				match(_t,DIFFUSE);
				_t = _t->getFirstChild();
				d=number(_t);
				_t = _retTree;
#line 256 "pov.g"
				p->setDiffuse(d);
#line 864 "SceneTreeParser.cpp"
				_t = __t132;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop133;
			}
			
		}
		_loop133:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == PHONG)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t135 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp77_AST_in = _t;
				match(_t,PHONG);
				_t = _t->getFirstChild();
				d=number(_t);
				_t = _retTree;
#line 257 "pov.g"
				p->setPhong(d);
#line 888 "SceneTreeParser.cpp"
				_t = __t135;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop136;
			}
			
		}
		_loop136:;
		} // ( ... )*
		{ // ( ... )*
		for (;;) {
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if ((_t->getType() == PHONG_SIZE)) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t138 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp78_AST_in = _t;
				match(_t,PHONG_SIZE);
				_t = _t->getFirstChild();
				d=number(_t);
				_t = _retTree;
#line 258 "pov.g"
				p->setPhongSize(d);
#line 912 "SceneTreeParser.cpp"
				_t = __t138;
				_t = _t->getNextSibling();
			}
			else {
				goto _loop139;
			}
			
		}
		_loop139:;
		} // ( ... )*
		_t = __t127;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return p;
}

Vector  SceneTreeParser::color_body(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
	Tracer traceInOut(this,"color_body",_t);
#line 269 "pov.g"
	Vector v;
#line 939 "SceneTreeParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST color_body_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t143 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp79_AST_in = _t;
		match(_t,RGB);
		_t = _t->getFirstChild();
		v=vector(_t);
		_t = _retTree;
		_t = __t143;
		_t = _t->getNextSibling();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = _t->getNextSibling();
	}
	_retTree = _t;
	return v;
}

void SceneTreeParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& )
{
}
const char* SceneTreeParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"\"SCENE\"",
	"\"OBJECT\"",
	"\"OBJECT_MOD\"",
	"\"POINT\"",
	"\"VECTOR\"",
	"\"NUMBER\"",
	"CAMERA",
	"LBRACE",
	"RBRACE",
	"LOCATION",
	"RIGHT",
	"UP",
	"DIRECTION",
	"LOOK_AT",
	"BACKGROUND",
	"LIGHT",
	"COMMA",
	"SPHERE",
	"POLYGON",
	"INTEGER",
	"PLANE",
	"INTERIOR",
	"IOR",
	"PIGMENT",
	"FINISH",
	"AMBIENT",
	"DIFFUSE",
	"PHONG",
	"PHONG_SIZE",
	"REFLECTION",
	"COLOR",
	"RGB",
	"LESS_THAN",
	"GREATER_THAN",
	"MINUS",
	"DOT",
	"SPECULAR",
	"RED",
	"BLUE",
	"GREEN",
	"TRANSMIT",
	"WS",
	0
};



