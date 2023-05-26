#pragma once
#include "..\BaseTokenRegex.h"
#include "..\..\Tokens\Operators\Operator.h"

class OperatorRegex : public BaseTokenRegex
{
public:
	OperatorRegex(Pointer*);
	bool TryParse(Token*&) override;
};

