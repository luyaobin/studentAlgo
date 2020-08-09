#include "algo2-1.h"
#include "c1.h"
#include "mergelist.h"

int main(int argc, char **argv)
{
    SqList La, Lb, Lc;
    int j, a[4] = {3,5,8,11}, b[7] = {2,6,8,9,11,15,20};
    InitList(&La);
    InitList(&Lb);

    for (j = 1; j <= 4; j++)
        ListInsert(&La, j, a[j - 1]);

    for (j = 1; j <= 7; j++)
        ListInsert(&Lb, j, b[j - 1]);


    printf("La = ");
    ListTraverse(La, print);
    printf("Lb = ");
    ListTraverse(Lb, print);
    MergeList(La, Lb, &Lc);
    printf("Lc=");
    ListTraverse(Lc, print);
    
}