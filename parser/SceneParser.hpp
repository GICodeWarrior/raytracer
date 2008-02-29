#ifndef INC_SceneParser_hpp_
#define INC_SceneParser_hpp_

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

#line 24 "SceneParser.hpp"
#include <antlr/config.hpp>
/* $ANTLR 2.7.6 (20070910): "pov.g" -> "SceneParser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "SceneParserTokenTypes.hpp"
#include <antlr/LLkParser.hpp>

class CUSTOM_API SceneParser : public ANTLR_USE_NAMESPACE(antlr)LLkParser, public SceneParserTokenTypes
{
#line 1 "pov.g"
#line 35 "SceneParser.hpp"
public:
	void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
protected:
	SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k);
public:
	SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf);
protected:
	SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k);
public:
	SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer);
	SceneParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state);
	int getNumTokens() const
	{
		return SceneParser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return SceneParser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return SceneParser::tokenNames;
	}
	public: void scene();
	public: void camera();
	public: void object();
	public: void background();
	public: void light();
	public: void camera_item();
	public: void point();
	public: void vector();
	public: void color();
	public: void sphere();
	public: void polygon();
	public: void plane();
	public: void number();
	public: void object_modifier();
	public: void interior();
	public: void pigment();
	public: void finish();
	public: void finish_item();
	public: void color_body();
public:
	ANTLR_USE_NAMESPACE(antlr)RefAST getAST()
	{
		return returnAST;
	}
	
protected:
	ANTLR_USE_NAMESPACE(antlr)RefAST returnAST;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 46;
#else
	enum {
		NUM_TOKENS = 46
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
	static const unsigned long _tokenSet_2_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_2;
	static const unsigned long _tokenSet_3_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_3;
	static const unsigned long _tokenSet_4_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_4;
	static const unsigned long _tokenSet_5_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_5;
	static const unsigned long _tokenSet_6_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_6;
	static const unsigned long _tokenSet_7_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_7;
	static const unsigned long _tokenSet_8_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_8;
};

#endif /*INC_SceneParser_hpp_*/
