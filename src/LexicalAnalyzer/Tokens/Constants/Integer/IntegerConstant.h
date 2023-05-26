#pragma once
#include "../Constant.h"

enum class NumberSystem
{
	Binary,
	Octal,
	Decimal,
	Hex,
};

class IntegerConstant :  public Constant
{
private:
	NumberSystem _numberSystem;
public:
	IntegerConstant(const char* startPtr, size_t length, NumberSystem numberSystem);
	std::string ToString() override;
};

