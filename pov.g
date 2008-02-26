options {
  language="Cpp";
}

////////// Parser:
class SceneParser extends Parser;
options {
  genHashLines = true;
  buildAST = true;
}

scene: (camera | object | background | light)+;

////////// Camera:
camera: CAMERA LBRACE! (camera_item)+ RBRACE!;

camera_item:
  LOCATION point |
  RIGHT vector |
  UP vector |
  DIRECTION vector |
  LOOK_AT vector;

////////// Atmospheric effects:
background: BACKGROUND LBRACE! color RBRACE!;

////////// Lights:
light: LIGHT LBRACE! point COMMA! color RBRACE!;

////////// Objects:
object: sphere | polygon | plane;

sphere: SPHERE LBRACE! point COMMA! number (object_modifier)* RBRACE!;
polygon: POLYGON LBRACE! INTEGER (COMMA! point)+ (object_modifier)* RBRACE!;
plane: PLANE LBRACE! vector COMMA! number (object_modifier)* RBRACE!;

////////// Object modifiers:
object_modifier: interior | pigment | finish;

interior: INTERIOR LBRACE! IOR number RBRACE!;
pigment: PIGMENT LBRACE! color RBRACE!;
finish: FINISH LBRACE! (finish_item)* RBRACE!;

finish_item:
  AMBIENT color |
  DIFFUSE number |
  PHONG number |
  PHONG_SIZE number |
  REFLECTION color;

////////// Color:
color: color_body | COLOR! color_body;
color_body: RGB! vector;

//////////

point: LT! number COMMA! number COMMA! number GT!;
vector: point;
number: INTEGER (DOT INTEGER)?;

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

plane returns [PrimitiveModel *m] {
    Vector n;
    double d;
  }
  : #(PLANE n=normal d=distance) {
    m = new Plane(n, d);
  };

normal returns [Vector v]
  : #(NORMAL v=vector);
distance returns [double d]
  : #(DISTANCE d=number);

////////// Object modifiers:

/*
object_modifier returns [Material m]
  : #(OBJECT_MODIFIER m=interior) |
    #(OBJECT_MODIFIER m=pigment) |
    #(OBJECT_MODIFIER m=finish);
*/

//interior: (interior_item)*

//interior_item
//  IOR number;

pigment returns [Material *m] {
    Color c;
  }
  : #(PIGMENT c=pigment_type) {
    m = new ColorMaterial(c);
  };

pigment_type returns [Color c]
  : #(PIGMENT_TYPE c=color);

//finish: (finish_item)*

//finish_item:
//  AMBIENT color |
//  DIFFUSE number |
//  PHONG number |
//  PHONG_SIZE number |
//  REFLECTION color;

/*
finish_item returns [vector <Material*> m] {
    m[0] = new Phong();
    m[1] = new Reflection();
    double value;
  }
  : #(FINISH_ITEM AMBIENT value=number) {
    m[0]->setAmbient(value);
  }
  | #(FINISH_ITEM DIFFUSE value=number) {
    m[0]->setDiffuse(value);
  }
  | #(FINISH_ITEM PHONG value=number) {
    m[0]->setPhong(value);
  }
  | #(FINISH_ITEM PHONG_SIZE value=number) {
    m[0]->setPhongSize(value);
  }
  | #(FINISH_ITEM REFLECTION value=number) {
    m[1]->setReflectivity(value);
  };
*/

////////// Lights:

light_source returns [Light l] {
    Point l;
    Color c;
  }
  : #(LIGHT_SOURCE l=location c=color) {
    l = Light(l, c);
  };

location returns [Point p]
  : #(LOCATION p=point);

////////// Color:

color returns [Color c]
  : #(COLOR c=color_body);

color_body returns [Color c]
  : #(COLOR_BODY c=color_vector);

color_vector returns [Color c] {
    Vector v;
  }
  : #(COLOR_VECTOR v=vector) {
    c = Color(v);
  };

//////////

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
  : i1:INTEGER i2:INTEGER {
    d = atod(i1->getText().c_str() + "." + i2->getText().c_str());
  };

