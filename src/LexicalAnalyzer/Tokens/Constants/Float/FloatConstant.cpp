#include "FloatConstant.h"

FloatConstant::FloatConstant(const char* startPtr, size_t length) : Constant(startPtr, length)
{ }

std::string FloatConstant::ToString()
{
	return "FloatConstant: " + Token::ToString();
}
