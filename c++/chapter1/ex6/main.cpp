#include <iostream>
using namespace std;
template<typename T>
bool is_sorted(const T *a, int n)
{
	bool cmp = *a > *(a + n - 1);

	for (int i = 0; i < n - 1; i++)
	{
		if (cmp != (*a > *(a + 1)))
		{
			return false;
		}	
		*a ++;
	}
	return true;
}

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
	int a[20];
	iota(a, 20, 20);
	cout << "hello world" << (is_sorted(a, 20) ? " true " : " false ") << a[19];
	return 0;
}
