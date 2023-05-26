#include "CharConstantRegex.h"

CharConstantRegex::CharConstantRegex(Pointer* pointer) : BaseTokenRegex(pointer)
{ }

bool CharConstantRegex::TryParse(Token * &token)
{
	Pointer tempPointer = Pointer(_pointer->GetCurrentPtr(), _pointer->GetRemainingLength());
	if (tempPointer.GetCurrent() != '\'')
		return false;

	while (tempPointer.MoveNext() && tempPointer.GetCurrent() != '\'')
	{
		if (tempPointer.GetCurrent() == '\\')
			tempPointer.MoveNext();

	}

	tempPointer.MoveNext();
	token = new CharConstant(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength());
	_pointer->MoveNext(tempPointer.GetPassedLength());
	return true;
}
