#pragma once
#include<map>
#include<string>
#include<list>
#include "IdentifierInfo.h"
#include "../Tokens/Identifiers/Identifier.h"
#include "../Exceptions/MultipleInitializationException.h"

class Scope
{
private:
	Scope* _parent;
	std::map<std::string, IdentifierInfo*> _identifiers;
	std::list<Scope*> _childs;
	int _investmentLevel;
public:
	Scope();
	Scope(Scope* parent);
	int GetInverstmentLevel();
	std::list<Scope*> GetChilds();
	Scope* CreateChildScope();
	Scope* GetParentScope();
	void AddIdentifier(Identifier*, IdentifierInfo*);
	std::map<std::string, IdentifierInfo*> GetIdentifiers();
};

