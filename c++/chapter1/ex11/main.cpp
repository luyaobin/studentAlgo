#include <iostream>
using namespace std;

template<class T>
int count(const T *beg, const T *end)
{
    int n = 0;
    while (beg != end)
    {
        n++;
        *beg ++;
    }

	if (n < 1)
	{
		throw "array length is too shorts";
	}

    return n;
}

template <class T>
int count(T a[], int n, const T& value)
{// Return number of occurrences of value in a[0:n-1].
   if (n < 1)
      throw "n must be >= 1";

   int theCount = 0;
   for (int i = 0; i < n; i++)
      if (a[i] == value)
         theCount++;
   return theCount;
}

int main(int argc, char ** argv)
{
	cout << "hello world";
	int a[100];
	try
	{
		count(a, 10, 20);
	}
	catch (const char * e)
	{
		cout << "this catch is const char*" << endl;
		cout << e;
	}
	
	return 0;
}
