#include "Scope.h"

Scope::Scope() : Scope(nullptr)
{
}

Scope::Scope(Scope* parent)
{
	_parent = parent;
	_identifiers = {};
	_childs = {};
	if (parent)
		_investmentLevel = parent->GetInverstmentLevel() + 1;
	else
		_investmentLevel = 0;
}

int Scope::GetInverstmentLevel()
{
	return _investmentLevel;
}

std::list<Scope*> Scope::GetChilds()
{
	return _childs;
}

Scope* Scope::CreateChildScope()
{
	Scope* child = new Scope(this);
	_childs.push_back(child);
	return child;
}

Scope* Scope::GetParentScope()
{
	return _parent;
}

void Scope::AddIdentifier(Identifier* identifier, IdentifierInfo* info)
{
	if (_identifiers.count(identifier->GetOriginalString()))
		throw new MultipleInitializationException(identifier);
	_identifiers.insert(std::pair<std::string, IdentifierInfo*>(identifier->GetOriginalString(), info));
}

std::map<std::string, IdentifierInfo*> Scope::GetIdentifiers()
{
	return _identifiers;
}
