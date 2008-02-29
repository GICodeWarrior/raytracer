/* $ANTLR 2.7.6 (20070910): "pov.g" -> "SceneParser.cpp"$ */
#include "SceneParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 1 "pov.g"
#line 8 "SceneParser.cpp"
SceneParser::SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

SceneParser::SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,1)
{
}

SceneParser::SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

SceneParser::SceneParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,1)
{
}

SceneParser::SceneParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,1)
{
}

void SceneParser::scene() {
	Tracer traceInOut(this, "scene");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST scene_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt3=0;
		for (;;) {
			switch ( LA(1)) {
			case CAMERA:
			{
				camera();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case SPHERE:
			case POLYGON:
			case PLANE:
			{
				object();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case BACKGROUND:
			{
				background();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			case LIGHT:
			{
				light();
				astFactory->addASTChild( currentAST, returnAST );
				break;
			}
			default:
			{
				if ( _cnt3>=1 ) { goto _loop3; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			}
			_cnt3++;
		}
		_loop3:;
		}  // ( ... )+
		scene_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 41 "pov.g"
		scene_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(SCENE))->add(scene_AST)));
#line 83 "SceneParser.cpp"
		currentAST.root = scene_AST;
		if ( scene_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			scene_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = scene_AST->getFirstChild();
		else
			currentAST.child = scene_AST;
		currentAST.advanceChildToEnd();
		scene_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = scene_AST;
}

void SceneParser::camera() {
	Tracer traceInOut(this, "camera");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST camera_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp1_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp1_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp1_AST);
		match(CAMERA);
		match(LBRACE);
		{ // ( ... )+
		int _cnt6=0;
		for (;;) {
			if (((LA(1) >= LOCATION && LA(1) <= LOOK_AT))) {
				camera_item();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt6>=1 ) { goto _loop6; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt6++;
		}
		_loop6:;
		}  // ( ... )+
		match(RBRACE);
		camera_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = camera_AST;
}

void SceneParser::object() {
	Tracer traceInOut(this, "object");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST object_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case SPHERE:
		{
			sphere();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case POLYGON:
		{
			polygon();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case PLANE:
		{
			plane();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		object_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 60 "pov.g"
		object_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(OBJECT))->add(object_AST)));
#line 173 "SceneParser.cpp"
		currentAST.root = object_AST;
		if ( object_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			object_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = object_AST->getFirstChild();
		else
			currentAST.child = object_AST;
		currentAST.advanceChildToEnd();
		object_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = object_AST;
}

void SceneParser::background() {
	Tracer traceInOut(this, "background");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST background_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp4_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp4_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp4_AST);
		match(BACKGROUND);
		match(LBRACE);
		color();
		astFactory->addASTChild( currentAST, returnAST );
		match(RBRACE);
		background_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = background_AST;
}

void SceneParser::light() {
	Tracer traceInOut(this, "light");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST light_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp7_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp7_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp7_AST);
		match(LIGHT);
		match(LBRACE);
		point();
		astFactory->addASTChild( currentAST, returnAST );
		match(COMMA);
		color();
		astFactory->addASTChild( currentAST, returnAST );
		match(RBRACE);
		light_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = light_AST;
}

void SceneParser::camera_item() {
	Tracer traceInOut(this, "camera_item");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST camera_item_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		switch ( LA(1)) {
		case LOCATION:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp11_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp11_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp11_AST);
			match(LOCATION);
			point();
			astFactory->addASTChild( currentAST, returnAST );
			camera_item_AST = currentAST.root;
			break;
		}
		case RIGHT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp12_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp12_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp12_AST);
			match(RIGHT);
			vector();
			astFactory->addASTChild( currentAST, returnAST );
			camera_item_AST = currentAST.root;
			break;
		}
		case UP:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp13_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp13_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp13_AST);
			match(UP);
			vector();
			astFactory->addASTChild( currentAST, returnAST );
			camera_item_AST = currentAST.root;
			break;
		}
		case DIRECTION:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp14_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp14_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp14_AST);
			match(DIRECTION);
			vector();
			astFactory->addASTChild( currentAST, returnAST );
			camera_item_AST = currentAST.root;
			break;
		}
		case LOOK_AT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp15_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp15_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp15_AST);
			match(LOOK_AT);
			vector();
			astFactory->addASTChild( currentAST, returnAST );
			camera_item_AST = currentAST.root;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_2);
	}
	returnAST = camera_item_AST;
}

void SceneParser::point() {
	Tracer traceInOut(this, "point");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST point_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		match(LESS_THAN);
		number();
		astFactory->addASTChild( currentAST, returnAST );
		match(COMMA);
		number();
		astFactory->addASTChild( currentAST, returnAST );
		match(COMMA);
		number();
		astFactory->addASTChild( currentAST, returnAST );
		match(GREATER_THAN);
		point_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 87 "pov.g"
		point_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(POINT))->add(point_AST)));
#line 337 "SceneParser.cpp"
		currentAST.root = point_AST;
		if ( point_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			point_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = point_AST->getFirstChild();
		else
			currentAST.child = point_AST;
		currentAST.advanceChildToEnd();
		point_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_3);
	}
	returnAST = point_AST;
}

void SceneParser::vector() {
	Tracer traceInOut(this, "vector");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vector_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		point();
		astFactory->addASTChild( currentAST, returnAST );
		vector_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 88 "pov.g"
		vector_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(VECTOR))->add(vector_AST)));
#line 366 "SceneParser.cpp"
		currentAST.root = vector_AST;
		if ( vector_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			vector_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = vector_AST->getFirstChild();
		else
			currentAST.child = vector_AST;
		currentAST.advanceChildToEnd();
		vector_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_4);
	}
	returnAST = vector_AST;
}

void SceneParser::color() {
	Tracer traceInOut(this, "color");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST color_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case RGB:
		{
			color_body();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case COLOR:
		{
			match(COLOR);
			color_body();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		color_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 82 "pov.g"
		color_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(COLOR))->add(color_AST)));
#line 414 "SceneParser.cpp"
		currentAST.root = color_AST;
		if ( color_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			color_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = color_AST->getFirstChild();
		else
			currentAST.child = color_AST;
		currentAST.advanceChildToEnd();
		color_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_5);
	}
	returnAST = color_AST;
}

void SceneParser::sphere() {
	Tracer traceInOut(this, "sphere");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST sphere_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp21_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp21_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp21_AST);
		match(SPHERE);
		match(LBRACE);
		point();
		astFactory->addASTChild( currentAST, returnAST );
		match(COMMA);
		number();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == INTERIOR || LA(1) == PIGMENT || LA(1) == FINISH)) {
				object_modifier();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop14;
			}
			
		}
		_loop14:;
		} // ( ... )*
		match(RBRACE);
		sphere_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = sphere_AST;
}

void SceneParser::polygon() {
	Tracer traceInOut(this, "polygon");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST polygon_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp25_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp25_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp25_AST);
		match(POLYGON);
		match(LBRACE);
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp27_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp27_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp27_AST);
		match(INTEGER);
		{ // ( ... )+
		int _cnt17=0;
		for (;;) {
			if ((LA(1) == COMMA)) {
				match(COMMA);
				point();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				if ( _cnt17>=1 ) { goto _loop17; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt17++;
		}
		_loop17:;
		}  // ( ... )+
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == INTERIOR || LA(1) == PIGMENT || LA(1) == FINISH)) {
				object_modifier();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop19;
			}
			
		}
		_loop19:;
		} // ( ... )*
		match(RBRACE);
		polygon_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = polygon_AST;
}

void SceneParser::plane() {
	Tracer traceInOut(this, "plane");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST plane_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp30_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp30_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp30_AST);
		match(PLANE);
		match(LBRACE);
		vector();
		astFactory->addASTChild( currentAST, returnAST );
		match(COMMA);
		number();
		astFactory->addASTChild( currentAST, returnAST );
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == INTERIOR || LA(1) == PIGMENT || LA(1) == FINISH)) {
				object_modifier();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop22;
			}
			
		}
		_loop22:;
		} // ( ... )*
		match(RBRACE);
		plane_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
	returnAST = plane_AST;
}

void SceneParser::number() {
	Tracer traceInOut(this, "number");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST number_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case MINUS:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp34_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp34_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp34_AST);
			match(MINUS);
			break;
		}
		case INTEGER:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp35_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp35_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, tmp35_AST);
		match(INTEGER);
		{
		switch ( LA(1)) {
		case DOT:
		{
			match(DOT);
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp37_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp37_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, tmp37_AST);
			match(INTEGER);
			break;
		}
		case RBRACE:
		case COMMA:
		case INTERIOR:
		case PIGMENT:
		case FINISH:
		case AMBIENT:
		case DIFFUSE:
		case PHONG:
		case PHONG_SIZE:
		case REFLECTION:
		case GREATER_THAN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		number_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 89 "pov.g"
		number_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(NUMBER))->add(number_AST)));
#line 631 "SceneParser.cpp"
		currentAST.root = number_AST;
		if ( number_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			number_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = number_AST->getFirstChild();
		else
			currentAST.child = number_AST;
		currentAST.advanceChildToEnd();
		number_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = number_AST;
}

void SceneParser::object_modifier() {
	Tracer traceInOut(this, "object_modifier");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST object_modifier_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case INTERIOR:
		{
			interior();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case PIGMENT:
		{
			pigment();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		case FINISH:
		{
			finish();
			astFactory->addASTChild( currentAST, returnAST );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		object_modifier_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(currentAST.root);
#line 68 "pov.g"
		object_modifier_AST = ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(astFactory->create(OBJECT_MOD))->add(object_modifier_AST)));
#line 684 "SceneParser.cpp"
		currentAST.root = object_modifier_AST;
		if ( object_modifier_AST!=ANTLR_USE_NAMESPACE(antlr)nullAST &&
			object_modifier_AST->getFirstChild() != ANTLR_USE_NAMESPACE(antlr)nullAST )
			  currentAST.child = object_modifier_AST->getFirstChild();
		else
			currentAST.child = object_modifier_AST;
		currentAST.advanceChildToEnd();
		object_modifier_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = object_modifier_AST;
}

void SceneParser::interior() {
	Tracer traceInOut(this, "interior");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST interior_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp38_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp38_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp38_AST);
		match(INTERIOR);
		match(LBRACE);
		match(IOR);
		number();
		astFactory->addASTChild( currentAST, returnAST );
		match(RBRACE);
		interior_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = interior_AST;
}

void SceneParser::pigment() {
	Tracer traceInOut(this, "pigment");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST pigment_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp42_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp42_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp42_AST);
		match(PIGMENT);
		match(LBRACE);
		color();
		astFactory->addASTChild( currentAST, returnAST );
		match(RBRACE);
		pigment_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = pigment_AST;
}

void SceneParser::finish() {
	Tracer traceInOut(this, "finish");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST finish_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp45_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp45_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp45_AST);
		match(FINISH);
		match(LBRACE);
		{ // ( ... )*
		for (;;) {
			if (((LA(1) >= AMBIENT && LA(1) <= REFLECTION))) {
				finish_item();
				astFactory->addASTChild( currentAST, returnAST );
			}
			else {
				goto _loop29;
			}
			
		}
		_loop29:;
		} // ( ... )*
		match(RBRACE);
		finish_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = finish_AST;
}

void SceneParser::finish_item() {
	Tracer traceInOut(this, "finish_item");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST finish_item_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		switch ( LA(1)) {
		case AMBIENT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp48_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp48_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp48_AST);
			match(AMBIENT);
			number();
			astFactory->addASTChild( currentAST, returnAST );
			finish_item_AST = currentAST.root;
			break;
		}
		case DIFFUSE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp49_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp49_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp49_AST);
			match(DIFFUSE);
			number();
			astFactory->addASTChild( currentAST, returnAST );
			finish_item_AST = currentAST.root;
			break;
		}
		case PHONG:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp50_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp50_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp50_AST);
			match(PHONG);
			number();
			astFactory->addASTChild( currentAST, returnAST );
			finish_item_AST = currentAST.root;
			break;
		}
		case PHONG_SIZE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp51_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp51_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp51_AST);
			match(PHONG_SIZE);
			number();
			astFactory->addASTChild( currentAST, returnAST );
			finish_item_AST = currentAST.root;
			break;
		}
		case REFLECTION:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp52_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
			tmp52_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, tmp52_AST);
			match(REFLECTION);
			number();
			astFactory->addASTChild( currentAST, returnAST );
			finish_item_AST = currentAST.root;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_8);
	}
	returnAST = finish_item_AST;
}

void SceneParser::color_body() {
	Tracer traceInOut(this, "color_body");
	returnAST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST color_body_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp53_AST = ANTLR_USE_NAMESPACE(antlr)nullAST;
		tmp53_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, tmp53_AST);
		match(RGB);
		vector();
		astFactory->addASTChild( currentAST, returnAST );
		color_body_AST = currentAST.root;
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_5);
	}
	returnAST = color_body_AST;
}

void SceneParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory )
{
	factory.setMaxNodeType(45);
}
const char* SceneParser::tokenNames[] = {
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

const unsigned long SceneParser::_tokenSet_0_data_[] = { 2UL, 0UL, 0UL, 0UL };
// EOF 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_0(_tokenSet_0_data_,4);
const unsigned long SceneParser::_tokenSet_1_data_[] = { 23856130UL, 0UL, 0UL, 0UL };
// EOF CAMERA BACKGROUND LIGHT SPHERE POLYGON PLANE 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_1(_tokenSet_1_data_,4);
const unsigned long SceneParser::_tokenSet_2_data_[] = { 258048UL, 0UL, 0UL, 0UL };
// RBRACE LOCATION RIGHT UP DIRECTION LOOK_AT 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_2(_tokenSet_2_data_,4);
const unsigned long SceneParser::_tokenSet_3_data_[] = { 437514240UL, 0UL, 0UL, 0UL };
// RBRACE LOCATION RIGHT UP DIRECTION LOOK_AT COMMA INTERIOR PIGMENT FINISH 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_3(_tokenSet_3_data_,4);
const unsigned long SceneParser::_tokenSet_4_data_[] = { 1306624UL, 0UL, 0UL, 0UL };
// RBRACE LOCATION RIGHT UP DIRECTION LOOK_AT COMMA 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_4(_tokenSet_4_data_,4);
const unsigned long SceneParser::_tokenSet_5_data_[] = { 4096UL, 0UL, 0UL, 0UL };
// RBRACE 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_5(_tokenSet_5_data_,4);
const unsigned long SceneParser::_tokenSet_6_data_[] = { 4195356672UL, 35UL, 0UL, 0UL };
// RBRACE COMMA INTERIOR PIGMENT FINISH AMBIENT DIFFUSE PHONG PHONG_SIZE 
// REFLECTION GREATER_THAN 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_6(_tokenSet_6_data_,4);
const unsigned long SceneParser::_tokenSet_7_data_[] = { 436211712UL, 0UL, 0UL, 0UL };
// RBRACE INTERIOR PIGMENT FINISH 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_7(_tokenSet_7_data_,4);
const unsigned long SceneParser::_tokenSet_8_data_[] = { 3758100480UL, 3UL, 0UL, 0UL };
// RBRACE AMBIENT DIFFUSE PHONG PHONG_SIZE REFLECTION 
const ANTLR_USE_NAMESPACE(antlr)BitSet SceneParser::_tokenSet_8(_tokenSet_8_data_,4);


