#include "Operator.h"

Operator::Operator(int operatorId, const char* startPtr, size_t length) : Token(TokenType::Operator, startPtr, length)
{
	_operatorId = operatorId;
}

std::string Operator::ToString()
{
	return "Operator: " + Token::ToString();
}

int FindOperatorId(std::string string)
{
	int i = 0;
	for (std::string punctuator : Operators)
	{
		if (punctuator == string)
			return i;
		i++;
	}
	return -1;
}