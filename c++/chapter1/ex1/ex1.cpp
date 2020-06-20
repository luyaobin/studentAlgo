#include "ex1.h"
#include "stdio.h"
void test()
{
    printf("\ntest pb");
}

void swapTest::swapErrorFunc(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapTest::swap(int & x, int & y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapTest::swapIntOverFlow(int &x, int &y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void swapTest::swapIntegetFunc(int &x, int &y)
{
    y = x ^ y;
    x = x ^ y;
    y = x ^ y;
}