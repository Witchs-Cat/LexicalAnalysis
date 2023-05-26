#pragma once
#include "../BaseTokenRegex.h"
#include "../../Tokens/Keywords/Keyword.h"
#include "../../Tokens/Identifiers/Identifier.h"

class KeywordOrIdentifierRegex : public BaseTokenRegex
{
public:
	KeywordOrIdentifierRegex(Pointer* pointer);
	bool TryParse(Token*& token) override;
};

