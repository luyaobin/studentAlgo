#include <iostream>
#include "countArrayTest.h"
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
    return n;
}

int main(int argc, char ** argv)
{
	cout << "hello world" << endl;
	countArrayTest t;
	int array[100];
	int i = 0;
	int ret = t.count(array);
    ret += count(begin(array), end(array));
	cout << "my count is :" << ret   << endl;
	return 0;
}
