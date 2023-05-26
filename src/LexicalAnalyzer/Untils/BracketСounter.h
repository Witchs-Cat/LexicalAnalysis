#pragma once
#include<list>
#include "../Tokens/Punctuators/Punctuator.h"
#include "../Exceptions/IncorrectBracketSequencesException.h"

class Bracket—ounter
{
private:
	std::list<Punctuator*> _brackets;
public:
	Bracket—ounter();
	void Add(Punctuator* bracket);
	size_t GetDepth();
};

