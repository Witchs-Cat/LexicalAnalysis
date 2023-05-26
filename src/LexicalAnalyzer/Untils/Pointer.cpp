#include "Pointer.h"

Pointer::Pointer(const char* headPtr, size_t length)
{
    _headPtr = headPtr;
    _currentPtr = headPtr;
    _length = length;
}

size_t Pointer::GetLength()
{
    return _length;
}

size_t Pointer::GetRemainingLength()
{
    return _length - GetPassedLength();
}

size_t Pointer::GetPassedLength()
{
    return _currentPtr - _headPtr;
}

bool Pointer::IsReachedEnd()
{
    return _headPtr + _length == _currentPtr;
}

const char* Pointer::GetHeadPtr()
{
    return _headPtr;
}

char Pointer::GetCurrent()
{
    return *_currentPtr;
}

const char* Pointer::GetCurrentPtr()
{
    return _currentPtr;
}

bool Pointer::CompareFollowing(std::string string)
{
    if (string.length() > GetRemainingLength())
    {
        return false;
    }

    Pointer temp = Pointer(_currentPtr, string.length());;

    for (int i = 0; !temp.IsReachedEnd(); i++)
    {
        if (temp.GetCurrent() != string[i])
            return false;
        temp.MoveNext();
    }

    return true;
}

bool Pointer::MoveNext()
{
    if (_currentPtr - _headPtr <= _length)
    {
        _currentPtr++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Pointer::MoveNext(size_t length)
{
    for (int i = 0; i < length; i++)
    {
        if (_currentPtr - _headPtr < _length)
        {
            _currentPtr++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Pointer::MovePrevious()
{
    if (_currentPtr > _headPtr)
    {
        _currentPtr--;
        return true;
    }
    else
    {
        return false;
    }
}


bool Pointer::MovePrevious(size_t length)
{
    for (int i = 0; i < length; i++)
    {
        if (_currentPtr > _headPtr)
        {
            _currentPtr--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
