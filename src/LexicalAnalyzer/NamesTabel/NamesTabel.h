#pragma once
#include "Scope.h"
#include "../Tokens/Identifiers/Identifier.h"

class NamesTabel
{
private:
	Scope* _global;
	Scope* _current;
public:
	NamesTabel();
	Scope* GetGlobalScope();
	void LinkToken(Identifier* identifier);
	void AddIdentifier(Identifier* identifier, IdentifierInfo* info);
	int GetCurrentInverstmentLevel();
	void UpScope();
	void DownScope();
};

