#pragma once
#include <string>
#include "../Tokens/Token.h"

enum IdentifierType
{
	Undefined,
	Function,
	Class,
	Struct,
	Variable,
};

class IdentifierInfo
{
private:
	IdentifierType _type;
	Token* _typeToken;
public:
	IdentifierInfo(Token* typeToken, IdentifierType type);
	IdentifierType GetType();
	std::string ToString();
};

std::ostream& operator<<(std::ostream& out, IdentifierInfo* info);