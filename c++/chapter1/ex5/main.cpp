#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

template<typename T>
void iota(T * a, const T& value, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = value + i;
	}
}

int main(int argc, char ** argv)
{
	cout << "hello world" << endl;
	int a[100];
	memset(a, 0, sizeof(a));
	iota(a, 25, 30);

    for (int i = 0; i < 100; i++)
    {
        cout << " " << i << ":" << a[i];
    }
	return 0;
}
