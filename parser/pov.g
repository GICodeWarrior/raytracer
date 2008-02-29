header "pre_include_hpp" {
class Phong;
class Reflection;
class Transmission;
class Sphere;
class Polygon;
class Plane;
class World;
class Light;
class BasicCamera;
class Camera;
class Color;
class Model;
class Point;
class Vector;
class Material;
class PrimitiveModel;
}

options {
  language="Cpp";
}

////////// Parser:
class SceneParser extends Parser;
options {
  genHashLines = true;
  buildAST = true;
}

tokens {
  SCENE = "SCENE";
  OBJECT = "OBJECT";
  OBJECT_MOD = "OBJECT_MOD";
  POINT = "POINT";
  VECTOR = "VECTOR";
  NUMBER = "NUMBER";
}

////////// Scene:
scene: (camera | object | background | light)+ {#scene = #([SCENE], #scene);};

////////// Camera:
camera: CAMERA^ LBRACE! (camera_item)+ RBRACE!;

camera_item:
  LOCATION^ point |
  RIGHT^ vector |
  UP^ vector |
  DIRECTION^ vector |
  LOOK_AT^ vector;

////////// Atmospheric effects:
background: BACKGROUND^ LBRACE! color RBRACE!;

////////// Lights:
light: LIGHT^ LBRACE! point COMMA! color RBRACE!;

////////// Objects:
object: (sphere | polygon | plane) {#object = #([OBJECT], #object);};

sphere: SPHERE^ LBRACE! point COMMA! number (object_modifier)* RBRACE!;
polygon: POLYGON^ LBRACE! INTEGER (COMMA! point)+ (object_modifier)* RBRACE!;
plane: PLANE^ LBRACE! vector COMMA! number (object_modifier)* RBRACE!;

////////// Object modifiers:
object_modifier: (interior | pigment | finish)
  {#object_modifier = #([OBJECT_MOD], #object_modifier);};

interior: INTERIOR^ LBRACE! IOR! number RBRACE!;
pigment: PIGMENT^ LBRACE! color RBRACE!;
finish: FINISH^ LBRACE! (finish_item)* RBRACE!;

finish_item:
  AMBIENT^ number |
  DIFFUSE^ number |
  PHONG^ number |
  PHONG_SIZE^ number |
  REFLECTION^ number;

////////// Color:
color: (color_body | COLOR! color_body) {#color = #([COLOR], #color);};
color_body: RGB^ vector;

////////// Misc:
point: LESS_THAN! number COMMA! number COMMA! number GREATER_THAN!
  {#point = #([POINT], #point);};
vector: point {#vector = #([VECTOR], #vector);};
number: (MINUS)? INTEGER (DOT! INTEGER)? {#number = #([NUMBER], #number);};

////////// Lexer:
class SceneLexer extends Lexer;
options {
  k=6;
  filter=WS;
}

RBRACE: "}";
LBRACE: "{";
LESS_THAN: "<";
GREATER_THAN: ">";
COMMA: ",";
DOT: ".";

MINUS: "-";
INTEGER: ('0'..'9')+;

CAMERA: "camera";
LOCATION: "location";
RIGHT: "right";
UP: "up";
DIRECTION: "direction";
LOOK_AT: "look_at";

BACKGROUND: "background";

SPHERE: "sphere";
POLYGON: "polygon";
PLANE: "plane";

INTERIOR: "interior";
IOR: "ior";

PIGMENT: "pigment";

FINISH: "finish";
AMBIENT: "ambient";
DIFFUSE: "diffuse";
PHONG: "phong";
PHONG_SIZE: "phong_size";
SPECULAR: "specular";
REFLECTION: "reflection";

LIGHT: "light_source";

COLOR: "color";
RGB: "rgb";
RED: "red";
BLUE: "blue";
GREEN: "green";
TRANSMIT: "transmit";

protected
WS    :  (' '|'\r'|'\t'|'\u000C'|'\n'); 

////////// TreeParser:
{
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
}
class SceneTreeParser extends TreeParser;

////////// Scene:
scene returns [World *w] {
    w = new World();
    Camera *cam;
    Color c;
    Light *l;
    Model *model;
  }
  : #(SCENE (cam=camera {w->setCamera(cam);})+
            (c=background {w->setBackground(c);})+
            (l=light {w->addLight(l);})+
            (model=object {w->add(model);}));

////////// Camera:
camera returns [BasicCamera *c] {
    c = new BasicCamera();
    Point p;
    Vector v;
  }
  : #(CAMERA (#(LOCATION p=point {c->setOrigin(p);}))*
             (#(RIGHT v=vector {c->setRight(v);}))*
             (#(UP v=vector {c->setUp(v);}))*
             (#(DIRECTION v=vector {c->setDirection(v);}))*
             (#(LOOK_AT v=vector {c->setLook(v);}))*);

////////// Atmospheric effects:
background returns [Color c] : #(BACKGROUND c=color);

////////// Lights:
light returns [Light *l] {
    l = new Light();
    Point p;
    Color c;
  }
  : #(LIGHT p=point c=color) {
    l->setOrigin(p);
    l->setTint(c);
  };

////////// Objects:
object returns [Model *m] : #(OBJECT (m=sphere | m=polygon | m=plane));

sphere returns [PrimitiveModel *model] {
    Material *m;
    Point center;
    double radius;
  }
  : #(SPHERE center=point radius=number {
        model = new Sphere(center, radius, Color::WHITE);
      }); // (m=object_modifier {m->bind(model); model = m;} )+);

polygon returns [Polygon *poly] {
    poly = new Polygon();
    Point p;
  }
  : #(POLYGON (p=point {poly->addVertex(p);})+);

plane returns [Plane *p] {
    Vector n;
    double d;
  }
  : #(PLANE n=vector d=number) {
    p = new Plane(n, d, Color::WHITE);
  };

////////// Object modifiers:
object_modifier returns [Material *m]
  : #(OBJECT_MOD (m=interior | m=pigment | m=finish));

interior returns [Transmission *t] {
    double ior;
  }
  : #(INTERIOR ior=number) {
    t = new Transmission(1.0, ior);
  };

pigment returns [Material *m] {
    Color c;
  }
  : #(PIGMENT c=color) {
    m = new ColorMaterial(c);
  };

finish returns [Phong *p] {
    p = new Phong();
    Color c;
    double d;
  }
  : #(FINISH (#(AMBIENT d=number {p->setAmbient(d);}))*
             (#(DIFFUSE d=number {p->setDiffuse(d);}))*
             (#(PHONG d=number {p->setPhong(d);}))*
             (#(PHONG_SIZE d=number {p->setPhongSize(d);}))*);

////////// Color:

color returns [Color c] {
    Vector v;
  }
  : #(COLOR v=color_body) {
    c = Color(v);
  };

color_body returns [Vector v]
  : #(RGB v=vector);

////////// Misc:

point returns [Point p] {
    double x,y,z;
  }
  : #(POINT x=number y=number z=number) {
     p = Point(x,y,z);
  };

vector returns [Vector v] {
    Point p;
  }
  : #(VECTOR p=point) {
    v = Vector(p.x, p.y, p.z);
  };

number returns [double d]
  : #(NUMBER i1:INTEGER i2:INTEGER) {
  	stringstream s;
  	s << i1->getText().c_str() << "." << i2->getText().c_str();
    d = atof(s.str().c_str());
  };

