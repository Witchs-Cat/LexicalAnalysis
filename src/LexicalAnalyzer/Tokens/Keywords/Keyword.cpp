#include "Keyword.h"

Keyword::Keyword(int id, const char* startPtr, size_t length):Token(TokenType::Keywords, startPtr, length)
{
	_keywordId = id;
}

int Keyword::GetKeywordId()
{ return _keywordId; }

bool Keyword::IsType()
{
	std::string strValue = Token::ToString();
	return (strValue == "int") || (strValue == "double") 
		|| (strValue == "char") || (strValue == "float");
}

std::string Keyword::ToString()
{
	return "Keyword: " + Token::ToString();
}

int KeywordIndex(std::string string)
{
	int i = 0;
	for (std::string keyword : Keywords)
	{
		if (keyword == string)
			return i;
		i++;
	}
	return -1;
}
