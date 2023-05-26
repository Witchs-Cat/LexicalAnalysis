#include "OperatorRegex.h"
OperatorRegex::OperatorRegex(Pointer* pointer):BaseTokenRegex(pointer)
{ }

bool OperatorRegex::TryParse(Token*& token)
{
	Pointer tempPointer = Pointer(_pointer->GetCurrentPtr(), _pointer->GetRemainingLength());
	int punctuatorId = FindOperatorId(std::string(tempPointer.GetCurrentPtr(), 1));

	if (punctuatorId < 0)
		return false;

	while (tempPointer.MoveNext())
	{
		int id = FindOperatorId(std::string(tempPointer.GetHeadPtr(), tempPointer.GetPassedLength()));
		if (id < 0)
			break;
		punctuatorId = id;
	}
	tempPointer.MovePrevious();
	token = new Operator(punctuatorId, tempPointer.GetHeadPtr(), tempPointer.GetPassedLength());
	_pointer->MoveNext(tempPointer.GetPassedLength());
	return true;
}
