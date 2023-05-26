#include "InvalidTokenException.h"

InvalidTokenException::InvalidTokenException(InvalidToken* token) : BaseException("InvalidTokenException: " + token->ToString())
{
	_token = token;
}

InvalidToken* InvalidTokenException::GetInvalidToken()
{
	return _token;
}
