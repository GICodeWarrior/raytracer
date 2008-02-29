#ifndef INC_SceneParserTokenTypes_hpp_
#define INC_SceneParserTokenTypes_hpp_

/* $ANTLR 2.7.6 (20070910): "pov.g" -> "SceneParserTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API SceneParserTokenTypes {
#endif
	enum {
		EOF_ = 1,
		SCENE = 4,
		OBJECT = 5,
		OBJECT_MOD = 6,
		POINT = 7,
		VECTOR = 8,
		NUMBER = 9,
		CAMERA = 10,
		LBRACE = 11,
		RBRACE = 12,
		LOCATION = 13,
		RIGHT = 14,
		UP = 15,
		DIRECTION = 16,
		LOOK_AT = 17,
		BACKGROUND = 18,
		LIGHT = 19,
		COMMA = 20,
		SPHERE = 21,
		POLYGON = 22,
		INTEGER = 23,
		PLANE = 24,
		INTERIOR = 25,
		IOR = 26,
		PIGMENT = 27,
		FINISH = 28,
		AMBIENT = 29,
		DIFFUSE = 30,
		PHONG = 31,
		PHONG_SIZE = 32,
		REFLECTION = 33,
		COLOR = 34,
		RGB = 35,
		LESS_THAN = 36,
		GREATER_THAN = 37,
		MINUS = 38,
		DOT = 39,
		SPECULAR = 40,
		RED = 41,
		BLUE = 42,
		GREEN = 43,
		TRANSMIT = 44,
		WS = 45,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_SceneParserTokenTypes_hpp_*/
