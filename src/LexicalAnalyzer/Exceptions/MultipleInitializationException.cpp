#include "MultipleInitializationException.h"

MultipleInitializationException::MultipleInitializationException(Identifier* identifier) : BaseException("MultipleInitializationException: "+ identifier->ToString())
{
	_identifier = identifier;
}

Identifier* MultipleInitializationException::GetIdentifier()
{
	return _identifier;
}
