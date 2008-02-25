options {
  language="Cpp";
}

class SceneParser extends Parser;
options {
  genHashLines = true;
  buildAST = true;
}

scene: (scene_item)+;

scene_item:
// language_directives |
//  global_settings |
  camera |
  object |
  atmospheric_effect |
  light_source;

////////// Camera:

camera: CAMERA! LBRACE! (camera_item)+ RBRACE!;

camera_item:
//  camera_type |
//  camera_identifier |
  camera_vector |
  camera_modifier;

/*
camera_type:
  "perspective" |
  "orthographic" |
  "fisheye" |
  "ultra_wide_angle" |
  "omnimax" |
  "panoramic" |
  "cylinder" cylinder_type |
  "spherical";
*/

camera_vector:
//  "sky" <sky> |
  LOCATION point |
  RIGHT vector |
  UP vector |
  DIRECTION vector;

camera_modifier:
//  normal |
//  transformation |
//  "angle" horizontal [vertical] |
//  "blur_samples" num_of_samples |
//  "aperture" size |
//  "focal_point" <point> |
//  "confidence" blur_confidence |
//  "variance" blur_variance |
  LOOK_AT vector;

////////// Atmospheric effects:

atmospheric_effect: background;
//atmospheric_effect: background | fog | sky_sphere | rainbow;

background: BACKGROUND LBRACE! color RBRACE!;

////////// Lights:

//light_source: "light_source" LBRACE! location COMMA color (light_modifiers)* RBRACE!;
light_source: LIGHT_SOURCE! LBRACE! location COMMA! color RBRACE!;
location: point;

/*
light_modifier:
  light_type |
  spotlight_item |
  area_light_items |
  general_light_modifiers;
*/

//light_type: "spotlight" | "shadowless" | "cylinder" | "parallel";

/*
spotlight_item:
  "radius" radius |
  "falloff" falloff |
  "tightness" tightness |
  "point_at" <spot>;
*/

//parallel_item: "point_at" <spot>;

/*
area_light_item:
  "area_light" <axis_1>, <axis_2>, size_1, size_2 |
  "adaptive" adaptive |
  "jitter" jitter |
  "circular" |
  "orient";
*/

/*
general_light_modifiers:
  "looks_like" LBRACE! object RBRACE! |
  transformation "fade_distance" fade_distance |
  "fade_power" fade_power |
  "media_attenuation" [bool] |
  "media_interaction" [bool] |
  "projected_through";
*/

////////// Objects:

object:
//  isosurface_object |
//  parametric_object |
//  csg_object |
//  "object" LBRACE! object_identifier (object_modifier)* RBRACE! |
  finite_solid_object |
  finite_patch_object |
  infinite_solid_object;

/*
finite_solid_object:
  blob | box | cone | cylinder | height_field | julia_fractal |
  lathe | prism | sphere | spheresweep | superellipsoid | sor |
  text | torus
*/
finite_solid_object: sphere;

/*
finite_patch_object:
    bicubic_patch | disc | mesh | mesh2 | polygon | triangle |
    smooth_triangle
*/
finite_patch_object: polygon;

//infinite_solid_object: plane | poly | cubic | quartic | quadric;
infinite_solid_object: plane;

//isosurface_object: isosurface;
//parametric_object: parametric;
//csg_object: union | intersection | difference | merge;

sphere: SPHERE! LBRACE! center COMMA! radius (object_modifier)* RBRACE!;
center: point;
radius: number;

polygon: POLYGON! LBRACE! number_of_points (COMMA! point)+ (object_modifier)* RBRACE!;
number_of_points: INTEGER;

plane: PLANE! LBRACE! normal COMMA! distance (object_modifier)* RBRACE!;
normal: vector;
distance: number;

////////// Object modifiers:

object_modifier:
//   transformation |
//   "clipped_by" LBRACE! (untextured_solid_object)* RBRACE! |
//   "clipped_by" LBRACE! bounded_by RBRACE!                 |
//   "bounded_by" LBRACE! (untextured_solid_object)* RBRACE! |
//   "bounded_by" LBRACE! clipped_by RBRACE!                 |
//   "no_shadow" |
//   "no_image" bool |
//   "no_reflection" bool |
//   "inverse" |
//   "sturm" bool |
//   "hierarchy" bool |
//   "double_illuminate" bool |
//   "hollow" bool |
//   "photons" LBRACE! (photon_items)+ RBRACE! |
   interior |
//   "material" LBRACE! material_identifier (material_item)* RBRACE! |
//   "texture" LBRACE! texture_body RBRACE! |
//   "interior_texture" LBRACE! texture_body RBRACE! |
   pigment |
//   "normal" LBRACE! normal_body RBRACE! |
   finish;

//interior: "interior" LBRACE! interior_identifier (interior_item)* RBRACE!;
interior: INTERIOR! LBRACE! (interior_item)* RBRACE!;

interior_item:
//  media |
//  "caustics" value |
//  "dispersion" value |
//  "dispersion_samples" samples |
//  "fade_distance" distance |
//  "fade_power" power |
//  "fade_color" color |
  IOR number;

/*
pigment: "pigment" LBRACE! (pigment_identifier)? (pigment_type)?
  (pigment_modifier)* RBRACE!;
*/
pigment: PIGMENT! LBRACE! pigment_type RBRACE!;

pigment_type:
//  "image_map" LBRACE! bitmap_type "bitmap.ext" image_map_mod* RBRACE! |
//  pattern_type |
  color;

/*
pigment_modifier:
  pattern_modifier |
  color_list |
  pigment_list |
  "color_map" LBRACE! color_map_body RBRACE! |
  "colour_map" LBRACE! color_map_body RBRACE! |
  "pigment_map" LBRACE! pigment_map_body RBRACE! |
  "quick_color" color |
  "quick_colour" color;
*/

//finish: "finish" LBRACE! (finish_identifier)? (finish_item)* RBRACE!;
finish: FINISH! LBRACE! (finish_item)* RBRACE!;

finish_item:
//  "reflection" LBRACE! color_reflecting_min (reflection_item)* RBRACE! |
//  "irid" LBRACE! irid_amount (irid_item)* RBRACE! |
//  "conserve_energy" bool |
//  "crand" amount |
  AMBIENT color |
  DIFFUSE number |
//  "brilliance" amount |
  PHONG number |
  PHONG_SIZE number |
//  SPECULAR number |
//  "roughness" amount |
//  "metallic" amount |
  REFLECTION color;

/*
reflection_item:
  color_reflection_max |
  "fresnel" bool_on_off |
  "falloff" float_falloff |
  "exponent" float_exponent |
  "metallic" float_metallic;
*/

//irid_item: "thickness" amount | "turbulence" amount;

////////// Global settings:

//global_settings: "global_settings" LBRACE! (global_settings_item)* RBRACE!

/*
global_settings_item:
  "adc_bailout" value |
  "ambient_light" color |
  "assumed_gamma" value |
  "hf_gray_16" bool |
  "irid_wavelength" color |
  "charset" global_charset |
  "max_intersections" number |
  "max_trace_level" number |
  "number_of_waves" number |
  "noise_generator" number |
  "radiosity" LBRACE! (radiosity_item)* RBRACE! |
  "photon" LBRACE! (photon_item)* RBRACE!;
*/

//GLOBAL_CHARSET: "ascii" | "utf8" | "sys";

////////// Color:

color:
  color_body |
  COLOR! color_body |
  COLOUR! color_body;

color_body:
//  color_identifier |
//  color_keyword_group |
  color_vector;

color_vector:
//  "rgbf" <4_term_vector> |
//  "rgbt" <4_term_vector> |
//  ("rgbft")? <5_term_vector> |
  RGB! vector;

//color_keyword_group: (color_keyword_item)+;

//color_keyword_item:
//  color_identifier |
//  RED number |
//  BLUE number |
//  GREEN number |
//  "filter" filter |
//  TRANSMIT number;

//////////

point: LT! number COMMA! number COMMA! number GT!;
vector: point;
number: INTEGER (DOT INTEGER)?;

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

LIGHT_SOURCE: "light_source";

COLOR: "color";
COLOUR: "colour";
RGB: "rgb";
RED: "red";
BLUE: "blue";
GREEN: "green";
TRANSMIT: "transmit";

class SceneTreeParser extends TreeParser;

////////// Objects:
/*
object:
  finite_solid_object |
  finite_patch_object |
  infinite_solid_object |
  light_source;

finite_solid_object: sphere;
finite_patch_object: polygon;
infinite_solid_object: plane;

sphere: SPHERE LBRACE! center COMMA radius (object_modifier)* RBRACE!;
center: point;
radius: number;

polygon: POLYGON LBRACE! number_of_points (COMMA point)+ (object_modifier)* RBRACE!;
number_of_points: INTEGER;

plane: PLANE LBRACE! normal COMMA distance (object_modifier)* RBRACE!;
*/
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

