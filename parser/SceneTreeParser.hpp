#ifndef INC_SceneTreeParser_hpp_
#define INC_SceneTreeParser_hpp_

#line 1 "pov.g"

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

#line 24 "SceneTreeParser.hpp"
#include <antlr/config.hpp>
#include "SceneParserTokenTypes.hpp"
/* $ANTLR 2.7.6 (20070910): "pov.g" -> "SceneTreeParser.hpp"$ */
#include <antlr/TreeParser.hpp>

class CUSTOM_API SceneTreeParser : public ANTLR_USE_NAMESPACE(antlr)TreeParser, public SceneParserTokenTypes
{
#line 1 "pov.g"
#line 33 "SceneTreeParser.hpp"
public:
	SceneTreeParser();
	static void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
	int getNumTokens() const
	{
		return SceneTreeParser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return SceneTreeParser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return SceneTreeParser::tokenNames;
	}
	public: World * scene(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: BasicCamera * camera(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Color  background(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Light * light(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Model * object(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Point  point(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Vector  vector(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Color  color(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: PrimitiveModel * sphere(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Polygon * polygon(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Plane * plane(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: double  number(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Material * object_modifier(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Transmission * interior(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Material * pigment(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Phong * finish(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
	public: Vector  color_body(ANTLR_USE_NAMESPACE(antlr)RefAST _t);
public:
	ANTLR_USE_NAMESPACE(antlr)RefAST getAST()
	{
		return returnAST;
	}
	
protected:
	ANTLR_USE_NAMESPACE(antlr)RefAST returnAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST _retTree;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 46;
#else
	enum {
		NUM_TOKENS = 46
	};
#endif
	
};

#endif /*INC_SceneTreeParser_hpp_*/
