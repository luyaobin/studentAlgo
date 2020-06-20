#include <iostream>
using namespace std;

template<class T>
void make2dArray(T ** &x, const int & numberOfRows, const int & numberOfcolumns)
{
	x = new T * [numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
		x[i] = new T [numberOfcolumns];
}

template<class T>
void make2dArray(T ** &x, const int & numberOfRows, const int *& rowSize)
{
	x = new T * [numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
		x[i] = new T [rowSize[i]];
}


int main(int argc, char ** argv)
{
	cout << "hello world";
	return 0;
}
