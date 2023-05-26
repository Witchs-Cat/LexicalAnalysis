#pragma once
#include "BaseException.h"
#include "../Tokens/Identifiers/Identifier.h"
class MultipleInitializationException : public BaseException
{
private:
	Identifier* _identifier;
public:
	MultipleInitializationException(Identifier* identifier);
	Identifier* GetIdentifier();
};

