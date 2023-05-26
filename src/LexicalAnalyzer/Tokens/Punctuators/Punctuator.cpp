#include "Punctuator.h"
#include "../Token.h"

Punctuator::Punctuator(int id, const char* startPtr, size_t length) : Token(TokenType::Punctuators, startPtr, length)
{
	_punctuatorId = id;
}

std::string Punctuator::ToString()
{
	return "Punctuator: " + std::string(GetStartPtr(), GetLength());
}

bool Punctuator::IsBracket()
{
	return _punctuatorId < 6;
}

bool Punctuator::IsOpenBracket()
{
	return IsBracket() && (_punctuatorId % 2 == 0);
}

bool Punctuator::IsCloseBracket()
{
	return IsBracket() && (_punctuatorId % 2 == 1);
}

int Punctuator::GetPunctuatorId()
{
	return _punctuatorId;
}

int FindPunctuatorId(std::string string)
{
	int i = 0;
	for (std::string punctuator : Punctuators)
	{
		if (punctuator == string)
			return i;
		i++;
	}
	return -1;
}