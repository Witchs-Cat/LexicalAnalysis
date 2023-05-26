#pragma once
#include "../Untils/Pointer.h"
#include "../Tokens/Token.h"

class BaseTokenRegex abstract
{
protected:
	Pointer* _pointer;
public:
	BaseTokenRegex(Pointer* pointer);
	virtual bool TryParse(Token*& token) abstract;
};

