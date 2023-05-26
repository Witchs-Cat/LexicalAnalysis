#pragma once
#include<vector>
#include<string>
#include <algorithm>
#include "../Token.h"
#include "../../Untils/Pointer.h"

static std::vector<std::string> Keywords = {
	"#include"      ,
	"#define"       ,
	"#region"       ,
	"class"         ,
	"auto"			,
	"break"			,
	"case"			,
	"char"			,
	"const"			,
	"continue"		,
	"default"		,
	"do"			,
	"double"		,
	"else"			,
	"enum"			,
	"extern"		,
	"float"			,
	"for"			,
	"goto"			,
	"if"			,
	"inline"		,
	"int"			,
	"long"			,
	"register"		,
	"restrict"		,
	"return"		,
	"short"			,
	"signed"		,
	"sizeof"		,
	"static"		,
	"struct"		,
	"switch"		,
	"typedef"		,
	"union"			,
	"unsigned"		,
	"void"			,
	"volatile"		,
	"while"			,
	"_Alignas"		,
	"_Alignof"		,
	"_Atomic"		,
	"_Bool1"		,
	"_Complex"		,
	"_Generic"		,
	"_Imaginary"	,
	"_Noreturn"		,
	"_Static_assert",
	"_Thread_local" 
};

int KeywordIndex(std::string string);

class Keyword : public Token
{
private:
	int _keywordId;
public:
	Keyword(int id, const char* startPtr, size_t length);
	int GetKeywordId();
	bool IsType();
	std::string ToString() override;
};