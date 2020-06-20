#include <iostream>
using namespace std;

int abc(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		throw "All parameters should be > 0";
	}
	else if (a < 0 && b < 0 && c < 0)
	{
		throw 1;
	}
	else if (a == 0 && b == 0 && c == 0)
	{
		throw 2;
	}
	return a + b * c;
}

int main(int argc, char ** argv)
{
	cout << "hello world" << endl;

	try
	{
		cout << abc(2, 0 , 4) << endl;
	}
	catch (const char * e)
	{
		cout << "this catch is const char*";
	}
	catch (int errno)
	{
		cout << "this catch is int*" << errno;
	}

	return 0;
}
