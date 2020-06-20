#include "c1.h"
#include "c2-1.h"
#include <math.h>

#ifndef OVERFLOW
#define OVERFLOW -2
#endif

Status InitList(SqList *L)
{
    (*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!(*L).elem)
        exit(OVERFLOW);

    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;

    return OK;
}

Status DestroyList(SqList *L)
{
    free((*L).elem);
    (*L).elem = nullptr;
    (*L).length = 0;
    (*L).listsize = 0;
    return OK;
}

Status ClearList(SqList *L)
{
    (*L).length = 0;
    return 0;
}

Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    return FALSE;
}

Status GetElem(SqList L, int i, ElemType * e)
{
    if (i < 1 || i > L.length)
        exit(ERROR);
    *e = *(L.elem + i - 1);
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    ElemType *p;
    int i = 1;
    p = L.elem;
    while(1 <= L.length && ! compare(*p++, e))
    {
        ++i;
    }
    if (i <= L.length)
        return i;
    return 0;
}
