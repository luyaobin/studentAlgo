#include "mergelist.h"

int comp(ElemType c1, ElemType c2)
{
    int i;
    if (c1 < c2)
        i = 1;
    else if (c1 == c2)
        i = 0;
    else
        i = -1;
    return i;
}


void MergeList(SqList La, SqList Lb, SqList *Lc)
{
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;

    (*Lc).listsize = La.length + Lb.length;
    pc = (*Lc).elem = (ElemType*)malloc((*Lc).listsize * sizeof(ElemType));
    if (!(*Lc).elem)
        exit(OVERFLOW);
    
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    
    while (pa <= pa_last && pb <= pb_last)
    {
        switch (comp(*pa, *pb))
        {
        case 0:
            pb++;
            break;
        case 1:
            *pc++=*pa++;
            break;
        case -1:
            *pc++ = *pb++;
            break;
        default:
            break;
        }
    }
    
    while (pa <= pa_last)
    {
        *pb++ = *pb++;
    }

    while (pb <= pb_last)
    {
        *pc++ = *pb++;
    }
    (*Lc).length = pc - (*Lc).elem;
}