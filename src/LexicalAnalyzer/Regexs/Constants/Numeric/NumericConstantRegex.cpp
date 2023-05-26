#include "NumericConstantRegex.h"
#include "../../../Tokens/InvalidToken.h"

NumericConstantRegex::NumericConstantRegex(Pointer* pointer) : BaseTokenRegex(pointer)
{ }


bool IsDigit(char symbol, NumberSystem numberSystem)
{
	if (numberSystem == NumberSystem::Hex)
		if ('a' <= tolower(symbol) && tolower(symbol) <= 'f')
			return true;
	return int('0') <= int(symbol) && int(symbol) <= int('9');
}

bool NumericConstantRegex::TryParse(Token*& token)
{
	NumberSystem numberSystem = NumberSystem::Decimal;
	Pointer tempPointer = Pointer(_pointer->GetCurrentPtr(), _pointer->GetRemainingLength());
	if (!IsDigit(tempPointer.GetCurrent(), numberSystem))
		return false;

	//число точек 0.00
	int dots = 0;

	//Проверка префикса;
	if (tempPointer.GetCurrent() == '0')
	{
		numberSystem = NumberSystem::Octal;
		tempPointer.MoveNext();
		switch (std::tolower((tempPointer.GetCurrent())))
		{
		case 'x':
			numberSystem = NumberSystem::Hex;
			tempPointer.MoveNext();
			break;
		case 'b':
			numberSystem = NumberSystem::Binary;
			tempPointer.MoveNext();
			break;
		default:
			break;
		}
	}

		
	//Парсинг числа
	
	while (true)
	{
		if (!tempPointer.MoveNext())
			break;

		if (IsDigit(tempPointer.GetCurrent(), numberSystem))
			continue;

		if (tempPointer.GetCurrent() == '.')
		{
			dots++;
			continue;
		}
		break;
	}

	//Проверка постфикса
	switch (std::tolower(tempPointer.GetCurrent()))
	{
	case 'f':
	case 'l':
	case 'u':
		tempPointer.MoveNext();
		break;
	default:
		break;
	}
	//если 12ll
	if (tempPointer.GetCurrent() == 'l')
		tempPointer.MoveNext();

	if (dots < 1)
	{
		token = new IntegerConstant(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength(), numberSystem);
		_pointer->MoveNext(tempPointer.GetPassedLength());
		return true;
	}

	if (dots > 1 || numberSystem != NumberSystem::Decimal)
	{

		token = new InvalidToken(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength(), "Invalid floating-point constant");
		_pointer->MoveNext(tempPointer.GetPassedLength());
		return true;
	}

	token = new FloatConstant(_pointer->GetCurrentPtr(), tempPointer.GetPassedLength());
	_pointer->MoveNext(tempPointer.GetPassedLength());

	return true;
}
