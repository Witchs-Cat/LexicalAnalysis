#pragma once

#include "../Token.h"
#include <vector>

static std::vector<std::string> Operators = {
	"...", ">>=", "<<=","::", "==", "%>",
	"&&", "||", "*=", "/=", "%=", "-=", ">=",
	"&=", "^=", "|=", "##", "<:", ":>", "<%",
	"+=", "<=", "!=", ">>", "<<", "->", "++",
	"--", "<", "&", "*", "+", "-", "~", "=", 
	"!", "?", "/", "%", "|", "^", ">",};

int FindOperatorId(std::string string);

class Operator : public Token
{
private:
	int _operatorId;
public:
	Operator(int OpeartorId, const char* startPtr, size_t length);
	std::string ToString() override;
};

