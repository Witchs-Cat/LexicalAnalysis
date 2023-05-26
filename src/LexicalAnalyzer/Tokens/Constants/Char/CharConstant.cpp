#include "CharConstant.h"

CharConstant::CharConstant(const char* startPtr, size_t length) : Constant(startPtr, length)
{
}

std::string CharConstant::ToString()
{
	return "CharConstant: " + Token::ToString();;
}
