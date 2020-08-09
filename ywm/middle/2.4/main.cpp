#include "algo2-1.h"
#include "c1.h"
#include "mergelist.h"

int main(int argc, char **argv)
{
    SqList La, Lb, Lc;
    int j;
    InitList(&La);
    for (j = 1; j <= 5; j++) {
        ListInsert(&La, j, j);
    }
    printf("La = ");
    ListTraverse(La, print);
    
    InitList(&Lb);
    for (j = 1; j < 5; j++) {
        ListInsert(&Lb, j, 2 * j);
    }
    printf("Lb = ");

    ListTraverse(Lb, print);
    MergeList(La, Lb, &Lc);
    printf("Lc = ");
    ListTraverse(Lc, print);
}