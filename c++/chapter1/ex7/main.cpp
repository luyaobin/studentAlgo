#include <iostream>
using namespace std;

template<typename T>
void iota(T * a, const T& value, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = value + i;
	}
}

template<typename T>
int pbmismatch(const T* a, const T *b, const int & n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *a << ":" << *b << endl;
		if (*a == *b)
		{
			*a ++;
			*b ++;
		}
		else
		{
			return i;
		}
	}
	return -1;
}
int main(int argc, char ** argv)
{
	cout << "hello world" << endl;
	int a[100];	
	int b[100];
	iota(a, 20, 20);
	iota(b, 20, 20);
	b [3] = 0;
	int ret =  pbmismatch(a, b, 10);
	cout << "less mismatch is : " << ret;

	return 0;
}
