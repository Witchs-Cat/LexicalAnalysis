#pragma once
#include <string>
#include <vector>
#include "../Token.h"
#include "../../Untils/Pointer.h"

static std::vector<std::string> Punctuators = {
	"[", "]", "(", ")", "{", "}", "#", ".", ",", ";", "::", ":"};

int FindPunctuatorId(std::string string);

class Punctuator : public Token
{
private:
	int _punctuatorId;
	std::string _value;
public:
	Punctuator(int id, const char* startPtr, size_t length);
	std::string ToString() override;
	bool IsBracket();
	bool IsOpenBracket();
	bool IsCloseBracket();
	int GetPunctuatorId();
};

