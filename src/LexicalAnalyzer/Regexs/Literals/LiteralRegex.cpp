#include "LiteralRegex.h"

LiteralRegex::LiteralRegex(Pointer* pointer) : BaseTokenRegex(pointer)
{
}

bool LiteralRegex::TryParse(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->GetCurrentPtr(), _pointer->GetRemainingLength());
	if (tempPointer.GetCurrent() == '"')
	{
		while (tempPointer.MoveNext() && (tempPointer.GetCurrent() != '"'))
		{
			if (tempPointer.GetCurrent() == '\\')
				tempPointer.MoveNext(2);
		}
		tempPointer.MoveNext();
		token = new Literal(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength());
		_pointer->MoveNext(tempPointer.GetPassedLength());
		return true;
	}
	return false;
}
