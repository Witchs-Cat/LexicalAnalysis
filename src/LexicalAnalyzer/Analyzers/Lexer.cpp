#include<vector>
#include "Lexer.h"
#include "../Regexs/Punctuators/PunctuatorRegex.h"
#include "../Regexs/Constants/Char/CharConstantRegex.h"
#include "../Regexs/Identifiers/KeywordOrIdentifierRegex.h"
#include "../Regexs/Literals/LiteralRegex.h"
#include "../Regexs/Constants/Numeric/NumericConstantRegex.h"
#include "../Regexs/Operators/OperatorRegex.h"
#include "../Tokens/InvalidToken.h"

Lexer::Lexer(std::string string) : Lexer(string.c_str(), string.length())
{ }

Lexer::Lexer(const char* input, size_t length)
{
	_pointer = new Pointer(input, length);
	_parsers = std::vector<BaseTokenRegex*>{
		new OperatorRegex(_pointer),
		new PunctuatorRegex(_pointer),
		new CharConstantRegex(_pointer),
		new NumericConstantRegex(_pointer),
		new LiteralRegex(_pointer),
		new KeywordOrIdentifierRegex(_pointer),
	};
}

bool IsSpace(char symbol)
{
	return (symbol == ' ') || (symbol == '\t') || (symbol == '\n') 
		|| symbol == ('\v') || (symbol == '\f') || (symbol == '\r');
}

bool Lexer::TrySkipSpaces()
{
	bool anySpace = IsSpace(_pointer->GetCurrent());
	while (IsSpace(_pointer->GetCurrent()) && _pointer->MoveNext())
	{ }
	return anySpace;
}

bool Lexer::TrySkipComments()
{
	if (_pointer->CompareFollowing("/*"))
	{
		while (_pointer->MoveNext() && !_pointer->CompareFollowing("*/"))
		{ }
		_pointer->MoveNext(2);
		return true;
	}
	else if (_pointer->CompareFollowing("//"))
	{
		while (_pointer->MoveNext() && _pointer->GetCurrent() != '\n')
		{ }
		_pointer->MoveNext();
		return true;
	}
	return false;
}

bool Lexer::TryParseInvalidToken(Token*& token)
{
	bool isReachedEnd = _pointer->IsReachedEnd();
	if (!isReachedEnd)
	{
		size_t currentPoint = _pointer->GetPassedLength();
		size_t lastPoint = currentPoint;
		while (!TryLex(token, false) && !isReachedEnd)
		{
			_pointer->MoveNext();
			lastPoint = _pointer->GetPassedLength();
			isReachedEnd = _pointer->IsReachedEnd();
		}

		token = new InvalidToken(_pointer->GetHeadPtr() + currentPoint, lastPoint - currentPoint, "An indefinite Token.");
		if (!isReachedEnd)
			_pointer->MovePrevious(_pointer->GetPassedLength() - lastPoint);
		return true;
	}
	return false;
}

/// <summary>
/// � ������ ��������� ��������, ����������������� ����� ����� ���������
/// </summary>
/// <return>
/// true - ���� ������� ��� �������, false ���� �����
/// </return>
bool Lexer::TryLex(Token*& token, bool catchInvalidToken)
{
	while (true)
	{
		//��������� � ������ � ����� ������ ���� � ������
		TrySkipSpaces();
		if (TrySkipComments())
			continue;

		//�������� ��������� ��������� ���� ������
		for (BaseTokenRegex* parser : _parsers)
		{
			if(parser->TryParse(token))
				return true;
		}

		//���� ������ ����� ��� �������, �� �� ����� �������, ������ ������� ����� �������� ������
		if (catchInvalidToken && TryParseInvalidToken(token))
			return true;

		return false;
	}
}
