#include "Analyzer.h"
#include "../Tokens/Keywords/Keyword.h"
#include "../Tokens/Punctuators/Punctuator.h"

Analyzer::Analyzer(const char* input, size_t length)
{
	_namesTabel = new NamesTabel();
	_tokens = {};
	_lexer = new Lexer(input, length);
	_brackets = new BracketÑounter();
}

void Analyzer::Parse()
{
	Token* token;
	while (_lexer->TryLex(token, true))
	{
		TokenType type = token->GetTokenType();
		if (type == TokenType::Invalid)
			throw new InvalidTokenException(dynamic_cast<InvalidToken*>(token));
		_tokens.push_back(token);
	}

	Token* typeToken = nullptr;
	IdentifierType identifierType = IdentifierType::Undefined;
	bool isKeywordContext = false;

	for (auto iterator = _tokens.begin(); iterator != _tokens.end(); iterator++)
	{
		token = *iterator;
		TokenType type = token->GetTokenType();

		if (type == TokenType::Keywords)
		{
			Keyword* keyword = dynamic_cast<Keyword*>(token);
			if (keyword->IsType())
			{
				typeToken = keyword;
				identifierType = IdentifierType::Variable;
				continue;
			}
			std::string origignalString = keyword->GetOriginalString();
			if (origignalString == "class")
			{
				typeToken = keyword;
				identifierType = IdentifierType::Class;
				continue;
			}
			if (origignalString == "struct")
			{
				typeToken = keyword;
				identifierType = IdentifierType::Struct;
				continue;
			}

			if (origignalString == "if" || origignalString == "for" || origignalString == "while")
				isKeywordContext = true;
			
		}

		if (type == TokenType::Identifiers)
		{
			Identifier* identifier = dynamic_cast<Identifier*>(token);
			if (typeToken == nullptr)
			{
				_namesTabel->LinkToken(identifier);
				if (identifier->IsType())
				{
					typeToken = identifier;
					identifierType = IdentifierType::Variable;
				}
				continue;
			}

			if (identifierType == IdentifierType::Variable)
			{
				Token* nextToken = *(++iterator);
				iterator--;

				if (nextToken != nullptr && nextToken->GetOriginalString() == "(")
				{
					identifierType = IdentifierType::Function;
				}
			}
			IdentifierInfo* info = new IdentifierInfo(typeToken, identifierType);
			_namesTabel->AddIdentifier(dynamic_cast<Identifier*>(token), info);
			continue;
		}

		if (token->GetOriginalString() != ",")
		{
			typeToken = nullptr;
			identifierType = IdentifierType::Undefined;
		}

		if (type == TokenType::Punctuators)
		{
			Punctuator* punctuator = dynamic_cast<Punctuator*>(token);

			if (!punctuator->IsBracket())
				continue;

			_brackets->Add(punctuator);

			if (_brackets->GetDepth() + isKeywordContext > _namesTabel->GetCurrentInverstmentLevel())
				_namesTabel->UpScope();
			else if (_brackets->GetDepth() < _namesTabel->GetCurrentInverstmentLevel())
				_namesTabel->DownScope();
			isKeywordContext = false;
			continue;
		}

	}

	if (_brackets->GetDepth() != 0)
		throw new IncorrectBracketSequencesException();
}

NamesTabel* Analyzer::GetNamesTabel()
{
	return _namesTabel;
}

std::list<Token*> Analyzer::GetTokens()
{
	return _tokens;
}



