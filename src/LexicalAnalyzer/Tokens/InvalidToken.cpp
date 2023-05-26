#include "InvalidToken.h"

InvalidToken::InvalidToken(const char* startPtr, size_t length) : InvalidToken(startPtr, length, "Not specified")
{
}

InvalidToken::InvalidToken(const char* startPtr, size_t length, std::string reason) : Token(TokenType::Invalid, startPtr, length)
{
	_reason = reason;
}

std::string InvalidToken::ToString()
{
	return "InvalidToken: " + Token::ToString() + " ["+_reason+ "]";
}
