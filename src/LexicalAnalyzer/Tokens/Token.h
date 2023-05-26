#pragma once
#include <string>
#include <iostream>

enum class TokenType { Invalid, Identifiers, Constants, Keywords, Punctuators, Operator, Literals };

class Token abstract
{
private:
	TokenType _TokenType;
	const char* _startPtr;
	size_t _length;

public:
	Token(TokenType id, const char* startPtr, size_t length);
	
	size_t GetLength();
	const char* GetStartPtr();
	TokenType GetTokenType();
	std::string GetOriginalString();
	virtual std::string ToString() abstract;
};

std::ostream& operator<<(std::ostream& out, Token* token);