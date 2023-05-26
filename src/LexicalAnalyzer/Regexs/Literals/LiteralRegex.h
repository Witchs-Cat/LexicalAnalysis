#pragma once
#include "../BaseTokenRegex.h"
#include "../../Tokens/Literals/Literal.h"

class LiteralRegex : public BaseTokenRegex
{
public:
	LiteralRegex(Pointer* pointer);
	bool TryParse(Token*& token) override;
};

