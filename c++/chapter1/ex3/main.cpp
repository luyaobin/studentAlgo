#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
void fill(T *beg, const T * end, const T value)
{
	while(beg != end)
	{
		beg = value;
		*beg ++;
	}
}

int main(int argc, char ** argv)
{
	printf("hello world");
	int a[100];
	fill(begin(a), end(a), 100);

	for(int i = 0; i < 100; i++)
	{
		cout << i << ":" << a[i] << " ";
	}
	return 0;
}
