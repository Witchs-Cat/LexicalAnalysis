#pragma once
#include "../Constant.h"

class FloatConstant: public Constant
{
public:
    FloatConstant(const char* startPtr, size_t length);
    std::string ToString() override;
};

