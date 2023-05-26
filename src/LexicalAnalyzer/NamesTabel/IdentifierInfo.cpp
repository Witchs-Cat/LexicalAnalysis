#include "IdentifierInfo.h"


IdentifierInfo::IdentifierInfo(Token* typeToken, IdentifierType type)
{
    _typeToken = typeToken;
    _type = type;
}

IdentifierType IdentifierInfo::GetType()
{
    return _type;
}

std::string IdentifierInfo::ToString()
{
    return "Type: " + std::to_string(_type) + " TypeToken: " + ((_typeToken == nullptr)? "NULL" : _typeToken->GetOriginalString());
}

std::ostream& operator<<(std::ostream& out, IdentifierInfo* info)
{
    out << info->ToString();
    return out;
}
