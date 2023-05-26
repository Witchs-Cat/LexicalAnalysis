#pragma once
#include "../../BaseTokenRegex.h"
#include "../../../Tokens/Constants/Char/CharConstant.h"

class CharConstantRegex :public BaseTokenRegex
{

public:
	CharConstantRegex(Pointer* pointer);
	bool TryParse(Token*& token) override;
};

