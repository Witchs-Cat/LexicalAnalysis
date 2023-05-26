#include "Token.h"
#include<string>

Token::Token(TokenType id, const char* startPtr, size_t length)
{
	_TokenType = id;
	_startPtr = startPtr;
	_length = length;
}

const char* Token::GetStartPtr()
{ return _startPtr; }

size_t Token::GetLength()
{ return _length;}

TokenType Token::GetTokenType()
{ return _TokenType; }

std::string Token::GetOriginalString()
{
	return std::string(_startPtr, _length);
}

std::string Token::ToString()
{ return std::string(_startPtr, _length); }
/*
std::string Token::ToString()
{ return std::to_string((int)_TokenType); }
*/

std::ostream& operator<<(std::ostream& out, Token* token)
{
	std::cout << token->ToString();
	return out;
}
