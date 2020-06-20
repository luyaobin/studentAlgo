#include "countArrayTest.h"

countArrayTest::countArrayTest()
{

}

int countArrayTest::count(int *array)
{
    int nCount = 0;
    if (array != nullptr)
        nCount = sizeof(array) / sizeof(array[0]);
    return nCount;
}
