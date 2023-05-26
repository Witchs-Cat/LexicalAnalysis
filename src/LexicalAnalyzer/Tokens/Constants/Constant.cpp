#include "Constant.h"

Constant::Constant(const char* startPtr, size_t length) : Token(TokenType::Constants, startPtr, length)
{ }

std::string Constant::ToString()
{
	return "Constant: " + Token::ToString();
}
