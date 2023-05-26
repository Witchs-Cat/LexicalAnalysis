#pragma once
#include "../../BaseTokenRegex.h"
#include "../../../Tokens/Constants/Integer/IntegerConstant.h"
#include "../../../Tokens/Constants/Float/FloatConstant.h"

class NumericConstantRegex : public BaseTokenRegex
{
public:
	NumericConstantRegex(Pointer* pointer);
	bool TryParse(Token*& token) override;
};

