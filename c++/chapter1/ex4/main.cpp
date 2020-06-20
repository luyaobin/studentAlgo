#include <iostream>
using namespace std;
template<typename T>
T inner_product(const T*a, const T*b, const int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}
	return sum;
}

int main(int argc, char ** argv)
{
	cout << "hello world" << endl;

	int a[50];
	int b[50];
	int ret = inner_product(a, b, 10);
	cout << "my test value : " << ret << endl;
	return 0;
}
