#pragma once
#include "../Constant.h"
class CharConstant : public Constant
{
public:
	CharConstant(const char* startPtr, size_t length);
	std::string ToString() override;
};

