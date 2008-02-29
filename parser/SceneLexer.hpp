#ifndef INC_SceneLexer_hpp_
#define INC_SceneLexer_hpp_

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

#line 24 "SceneLexer.hpp"
#include <antlr/config.hpp>
/* $ANTLR 2.7.6 (20070910): "pov.g" -> "SceneLexer.hpp"$ */
#include <antlr/CommonToken.hpp>
#include <antlr/InputBuffer.hpp>
#include <antlr/BitSet.hpp>
#include "SceneParserTokenTypes.hpp"
#include <antlr/CharScanner.hpp>
class CUSTOM_API SceneLexer : public ANTLR_USE_NAMESPACE(antlr)CharScanner, public SceneParserTokenTypes
{
#line 1 "pov.g"
#line 35 "SceneLexer.hpp"
private:
	void initLiterals();
public:
	bool getCaseSensitiveLiterals() const
	{
		return true;
	}
public:
	SceneLexer(ANTLR_USE_NAMESPACE(std)istream& in);
	SceneLexer(ANTLR_USE_NAMESPACE(antlr)InputBuffer& ib);
	SceneLexer(const ANTLR_USE_NAMESPACE(antlr)LexerSharedInputState& state);
	ANTLR_USE_NAMESPACE(antlr)RefToken nextToken();
	public: void mRBRACE(bool _createToken);
	public: void mLBRACE(bool _createToken);
	public: void mLESS_THAN(bool _createToken);
	public: void mGREATER_THAN(bool _createToken);
	public: void mCOMMA(bool _createToken);
	public: void mDOT(bool _createToken);
	public: void mMINUS(bool _createToken);
	public: void mINTEGER(bool _createToken);
	public: void mCAMERA(bool _createToken);
	public: void mLOCATION(bool _createToken);
	public: void mRIGHT(bool _createToken);
	public: void mUP(bool _createToken);
	public: void mDIRECTION(bool _createToken);
	public: void mLOOK_AT(bool _createToken);
	public: void mBACKGROUND(bool _createToken);
	public: void mSPHERE(bool _createToken);
	public: void mPOLYGON(bool _createToken);
	public: void mPLANE(bool _createToken);
	public: void mINTERIOR(bool _createToken);
	public: void mIOR(bool _createToken);
	public: void mPIGMENT(bool _createToken);
	public: void mFINISH(bool _createToken);
	public: void mAMBIENT(bool _createToken);
	public: void mDIFFUSE(bool _createToken);
	public: void mPHONG(bool _createToken);
	public: void mPHONG_SIZE(bool _createToken);
	public: void mSPECULAR(bool _createToken);
	public: void mREFLECTION(bool _createToken);
	public: void mLIGHT(bool _createToken);
	public: void mCOLOR(bool _createToken);
	public: void mRGB(bool _createToken);
	public: void mRED(bool _createToken);
	public: void mBLUE(bool _createToken);
	public: void mGREEN(bool _createToken);
	public: void mTRANSMIT(bool _createToken);
	protected: void mWS(bool _createToken);
private:
	
};

#endif /*INC_SceneLexer_hpp_*/
