#include <iostream>
#include "ex1.h"
using namespace std;
int main(int argc, char ** argv)
{
	cout << "hello world";
	swapTest t;
	int a = 10;
	int b = 11;
	t.swapErrorFunc(a, b);
	cout << a << b << endl;
	t.swap(a, b);
	cout << a << b << endl;
	t.swapIntOverFlow(a, b);
	cout << a << b << endl;
	t.swapIntegetFunc(a, b);
	cout << a << b << endl;
	return 0;
}

