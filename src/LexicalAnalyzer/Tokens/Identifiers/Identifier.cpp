#include "Identifier.h"

Identifier::Identifier(const char* startPtr, size_t length) : Token(TokenType::Identifiers, startPtr, length)
{
	_info = nullptr;
}

bool Identifier::IsType()
{
	if (_info == nullptr)
		return false;
	return _info->GetType() == IdentifierType::Class || _info->GetType() == IdentifierType::Struct;
}

void Identifier::LinkToNamesTabel(IdentifierInfo* info)
{
	_info = info;
}

std::string Identifier::ToString()
{
	return "Idenrifier: " + Token::ToString();
}
