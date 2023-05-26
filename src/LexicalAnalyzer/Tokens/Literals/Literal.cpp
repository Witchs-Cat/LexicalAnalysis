#include "Literal.h"

Literal::Literal( const char* startPtr, size_t length) : Token(TokenType::Literals, startPtr, length)
{
}

std::string Literal::ToString()
{      
    return "Literal: " + Token::ToString();
}
