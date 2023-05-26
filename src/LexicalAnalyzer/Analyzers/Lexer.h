#pragma once
#include <vector>
#include "../Regexs/BaseTokenRegex.h"

class Lexer
{
private:
	Pointer* _pointer;
	std::vector<BaseTokenRegex*> _parsers;
public:
	Lexer(std::string string);
	Lexer(const char*, size_t length);
private:
	bool TrySkipSpaces();
	bool TrySkipComments();
	bool TryParseInvalidToken(Token*&);
public:
	bool TryLex(Token*&, bool catchInvalidToken);
};

