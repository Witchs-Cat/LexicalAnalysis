#pragma once
#include <string>

#include "../Token.h"
#include "../../Untils/Pointer.h"

class Literal: public Token
{
public:
	Literal(const char* startPtr, size_t length);
	std::string ToString() override;
};
