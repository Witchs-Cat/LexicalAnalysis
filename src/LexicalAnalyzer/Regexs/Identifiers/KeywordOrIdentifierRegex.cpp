#include "KeywordOrIdentifierRegex.h"

KeywordOrIdentifierRegex::KeywordOrIdentifierRegex(Pointer* pointer) : BaseTokenRegex(pointer)
{
}

bool IsFirstAllowedCharacter(char symbol)
{
	return (symbol >= '@' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || symbol == '_';
}

bool IsSubsequentAllowedCharacter(char symbol)
{
	return (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || symbol == '_' || isdigit(symbol);
}


bool KeywordOrIdentifierRegex::TryParse(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->GetCurrentPtr(), _pointer->GetRemainingLength());
	if (!IsFirstAllowedCharacter(tempPointer.GetCurrent()))
		return false;

	while (tempPointer.MoveNext() && IsSubsequentAllowedCharacter(tempPointer.GetCurrent()))
	{
	}

	int keywordIndex = KeywordIndex(std::string(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength()));

	if (keywordIndex < 0)
		token = new Identifier(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength());
	else
		token = new Keyword(keywordIndex, _pointer->GetCurrentPtr(), tempPointer.GetPassedLength());

	_pointer->MoveNext(tempPointer.GetPassedLength());
	return true;
}
