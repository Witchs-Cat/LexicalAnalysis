#include "IntegerConstant.h"

IntegerConstant::IntegerConstant(const char* startPtr, size_t length, NumberSystem numberSystem) : Constant(startPtr, length)
{
	_numberSystem = numberSystem;
}

std::string IntegerConstant::ToString()
{
	return "IntegerConstant: " + Token::ToString();
}
