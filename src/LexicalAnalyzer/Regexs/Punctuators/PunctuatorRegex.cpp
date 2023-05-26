#include "PunctuatorRegex.h"

PunctuatorRegex::PunctuatorRegex(Pointer* pointer) : BaseTokenRegex(pointer)
{ }

bool PunctuatorRegex::TryParse(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->GetCurrentPtr(), _pointer->GetRemainingLength());
	int punctuatorId = FindPunctuatorId(std::string(tempPointer.GetCurrentPtr(), 1));

	if (punctuatorId < 0)
		return false;

	while (tempPointer.MoveNext())
	{
		int id = FindPunctuatorId(std::string(tempPointer.GetHeadPtr(), tempPointer.GetPassedLength()));
		if (id < 0)
			break;
		punctuatorId = id;
	}
	tempPointer.MovePrevious();
	token = new Punctuator(punctuatorId, tempPointer.GetHeadPtr(), tempPointer.GetPassedLength());
	_pointer->MoveNext(tempPointer.GetPassedLength());
	return true;
}
