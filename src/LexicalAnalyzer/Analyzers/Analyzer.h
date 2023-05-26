#pragma once
#include "../NamesTabel/NamesTabel.h"
#include "Lexer.h"
#include "../Exceptions/InvalidTokenException.h"
#include "../Untils/Bracket—ounter.h"
#include "../Exceptions/IncorrectBracketSequencesException.h"

class Analyzer
{
private:
	NamesTabel* _namesTabel;
	std::list<Token*> _tokens;
	Lexer* _lexer;
	Bracket—ounter* _brackets;
public:
	Analyzer(const char* input, size_t length);
	void Parse();
	NamesTabel* GetNamesTabel();
	std::list<Token*> GetTokens();
};

