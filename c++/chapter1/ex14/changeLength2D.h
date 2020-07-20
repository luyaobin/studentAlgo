#pragma once
#include <iostream>
using namespace std;
class illegalParameterValue
{
public:
	illegalParameterValue()
		: message("illegal parameter value"){}
	illegalParameterValue(char *theMessage)
		: message(theMessage){}
	void outputMessage() { cout << message << endl; }
private:
	string message;
};

template<class T>
void changeLength1D(T *&a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParameterValue("new length must be >= 0");

	T *temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete []a;
	a = temp;
}


template<class T>
void changeLength2D(T **&a, int oldRows, int oldColumns, int newRows, int newColumns)
{
	if (newRows < 0 || newColumns < 0)
		throw illegalParameterValue("new rows or columns  must be >= 0");
	T **temp = new T * [newRows];
	for (int i = 0; i < newColumns; ++i)
	{
		changeLength1D(temp[i], oldColumns, newColumns);
	}
	delete [][]a;
	a = temp;
}
