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
  SCENE;
  OBJECT;
  OBJECT_MOD;
  POINT;
  NUMBER;
}

////////// Scene:
scene: SCENE^ (camera | object | background | light)+;

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
object: OBJECT^ (sphere | polygon | plane);

sphere: SPHERE^ LBRACE! point COMMA! number (object_modifier)* RBRACE!;
polygon: POLYGON^ LBRACE! INTEGER (COMMA! point)+ (object_modifier)* RBRACE!;
plane: PLANE^ LBRACE! vector COMMA! number (object_modifier)* RBRACE!;

////////// Object modifiers:
object_modifier: OBJECT_MOD^ (interior | pigment | finish);

interior: INTERIOR^ LBRACE! IOR number RBRACE!;
pigment: PIGMENT^ LBRACE! color RBRACE!;
finish: FINISH^ LBRACE! (finish_item)* RBRACE!;

finish_item:
  AMBIENT^ color |
  DIFFUSE^ number |
  PHONG^ number |
  PHONG_SIZE^ number |
  REFLECTION^ color;

////////// Color:
color: color_body | COLOR! color_body;
color_body: RGB^ vector;

////////// Misc:
point: POINT^ LT! number COMMA! number COMMA! number GT!;
vector: VECTOR^ point;
number: NUMBER^ INTEGER (DOT INTEGER)?;

////////// Lexer:
class SceneLexer extends Lexer;
options {
  k=6;
}

RBRACE: "}";
LBRACE: "{";
LT: "<";
GT: ">";
COMMA: ",";
DOT: ".";

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

////////// TreeParser:
class SceneTreeParser extends TreeParser;

////////// Scene:
scene returns [World *w] {
    w = new World();
    Camera *cam;
    Color color;
    Light *l;
    Model *m;
  }
  : #(SCENE (cam=camera {w->setCamera(cam);})+
            (color=background {w->setBackground(color);})+
            (l=light {w->addLight(l);})+
            (model=object {w->add(model);}));

////////// Camera:
camera returns [Camera *c] {
    c = new Camera();
    Point p;
    Vector v;
  }
  : #(CAMERA (LOCATION p=point {c->setLocation(p);})+
             (RIGHT v=vector {c->setRight(v);})+
             (UP v=vector {c->setUp(v);})+
             (DIRECTION v=vector {c->setDirection(v);})+
             (LOOK_AT v=vector {c->setLookAt(v);})+);

////////// Atmospheric effects:
background returns [Color c] : #(BACKGROUND c=color);

////////// Lights:
light returns [Light *l] {
    l = new Light();
    Point p;
    Color c;
  }
  : #(LIGHT p=point c=color) {
    l->setLocation(p);
    l->setTint(c);
  };

////////// Objects:
object returns [Model *m] : #(OBJECT (m=sphere | m=polygon | m=plane));

sphere returns [Model *model] {
    Material *m;
    Point center;
    double radius;
  }
  : #(SPHERE center=point radius=number {
        model = new Sphere(center, radius);
      } (m=object_modifier {m->attach(model); model = m;} )+);

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
    p = new Plane(n, d);
  };

////////// Object modifiers:
object_modifier returns [Material *m]
  : #(OBJECT_MOD (m=interior | m=pigment | m=finish));

interior returns [Trasmission *t] {
    double ior;
  }
  : #(INTERIOR ior=number) {
    t = new Transmission(ior);
  };

pigment returns [ColorMaterial *c] {
    Color c;
  }
  : #(PIGMENT c=color) {
    c = new ColorMaterial(c);
  };

finish returns [Phong *p] {
    p = new Phong();
    Color c;
    double d;
  }
  : #(FINISH (AMBIENT d=number {p->setAmbient(d);})+
             (DIFFUSE d=number {p->setDiffuse(d);})+
             (PHONG d=number {p->setPhong(d);})+
             (PHONG_SIZE d=number {p->setPhongSize(d);})+);

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
    d = atod(i1->getText().c_str() + "." + i2->getText().c_str());
  };

