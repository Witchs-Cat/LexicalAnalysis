#pragma once
#include <string>
#include "../Token.h"
#include "../../Untils/Pointer.h"
#include "../../NamesTabel/IdentifierInfo.h"

class Identifier : public Token
{
private:
	IdentifierInfo* _info;
public:
	Identifier(const char* startPtr, size_t length);
	bool IsType();
	void LinkToNamesTabel(IdentifierInfo* info);
	std::string ToString() override;
};

