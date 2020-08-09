#include "mergelist.h"

void MergeList(SqList La, SqList Lb, SqList *Lc)
{
    int i = 1, j = 1, k = 0;
    int La_len, Lb_len;
    ElemType ai, bj;

    InitList(Lc);
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    while (i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        if (ai <= bj) {
            ListInsert(Lc, ++k, ai);
            ++i;
        }
        else {
            ListInsert(Lc, ++k, bj);
            ++j;
        }

        while (i <= La_len)
        {
            GetElem(La, i++, &ai);
            ListInsert(Lc, ++k, ai);
        }
        
        while (j <= Lb_len) 
        {
            GetElem(Lb, j++, &bj);
            ListInsert(Lc, ++k, bj);
        }
        
    }
}