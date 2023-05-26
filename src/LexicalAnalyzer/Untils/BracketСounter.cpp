#include "Bracket�ounter.h"

Bracket�ounter::Bracket�ounter()
{
	_brackets = {};
}

void Bracket�ounter::Add(Punctuator* bracket)
{
	if (!bracket->IsBracket())
		return;

	if (bracket->IsOpenBracket())
	{
		_brackets.push_back(bracket);
		return;
	}

	if (_brackets.empty())
		throw new IncorrectBracketSequencesException();

	Punctuator* top = _brackets.back();
	if (top->GetPunctuatorId() == bracket->GetPunctuatorId() - 1)
	{
		_brackets.pop_back();
		return;
	}
	else
	{
		throw new IncorrectBracketSequencesException();
	}
}

size_t Bracket�ounter::GetDepth()
{
	int count = 0;
	for (Punctuator* bracket : _brackets)
		count += (bracket->GetOriginalString() == "{");
	
	return count;
}
