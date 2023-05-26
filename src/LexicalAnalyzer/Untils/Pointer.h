#pragma once
#include<string>

class Pointer
{
private:
	const char* _headPtr;
	const char* _currentPtr;
	size_t _length;

public:
	Pointer(const char* headPtr, size_t length);

	size_t GetLength();
	size_t GetRemainingLength();
	size_t GetPassedLength();

	bool IsReachedEnd();
	
	char GetCurrent();
	const char* GetHeadPtr();
	const char* GetCurrentPtr();

	bool CompareFollowing(std::string string);

	bool MoveNext();
	bool MoveNext(size_t length);
	bool MovePrevious();
	bool MovePrevious(size_t length);
};

