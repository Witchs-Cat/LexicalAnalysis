#pragma once
#include "../BaseTokenRegex.h"
#include "../../Tokens/Punctuators/Punctuator.h"

class PunctuatorRegex : public BaseTokenRegex
{
public:
	PunctuatorRegex(Pointer* pointer);
	bool TryParse(Token*& token) override;
};

