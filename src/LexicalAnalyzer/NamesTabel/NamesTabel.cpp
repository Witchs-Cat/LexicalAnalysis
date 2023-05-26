#include "NamesTabel.h"
#include<stack>
NamesTabel::NamesTabel()
{
	_global = new Scope();
	_current = _global;
}

Scope* NamesTabel::GetGlobalScope()
{
	return _global;
}

void NamesTabel::LinkToken(Identifier* identifier)
{
	std::stack<Scope*> scopes;
	scopes.push(_current);

	bool isLinked = false;

	while (!scopes.empty())
	{
		Scope* scope = scopes.top();
		scopes.pop();

		std::map<std::string, IdentifierInfo*> scopeIdentifiers = scope->GetIdentifiers();
		auto iterator = scopeIdentifiers.find(identifier->GetOriginalString());
		if (iterator != scopeIdentifiers.end())
		{
			identifier->LinkToNamesTabel((*iterator).second);
			isLinked = true;
			break;
		}

		if (scope->GetParentScope() != nullptr)
			scopes.push(scope->GetParentScope());
	}

	/*if (!isLinked)
		AddIdentifier(identifier, new IdentifierInfo(nullptr, Undefined));*/
}

void NamesTabel::AddIdentifier(Identifier* token, IdentifierInfo* info)
{
	_current->AddIdentifier(token, info);
}

int NamesTabel::GetCurrentInverstmentLevel()
{
	return _current->GetInverstmentLevel();
}

void NamesTabel::DownScope()
{
	Scope* temp = _current->GetParentScope();
	if (temp != nullptr)
		_current = temp;
}

void NamesTabel::UpScope()
{
	_current = _current->CreateChildScope();
}
