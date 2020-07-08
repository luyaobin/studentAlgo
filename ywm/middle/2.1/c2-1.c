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

int ListLength(SqList L)
{
	return L.length;
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

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && *p != cur_e)
    {
        p++;
        i++;
    }
    if (i > L.length)
        return INFEASIBLE;
    else
    {
        *pre_e = *--p;
        return OK;
    }
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
    int i = 1;
    ElemType *p = L.elem;
    while(i < L.length && *p != cur_e)
    {
        i++;
        p++;
    }

    if (i == L.length)
    	return INFEASIBLE;
    else
    {
    	*next_e = *++p;
    	return OK;
    }
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	ElemType *newbase, *q, *p;
	if (i < 1 || i > (*L).length + 1)
		return ERROR;

	if ((*L).length >= (*L).listsize)
	{
		newbase = (ElemType*)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}

	q = (*L).elem + i - 1;
	for(p = (*L).elem + (*L).length -1; p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++(*L).length;
	return OK;
}

Status Delete(SqList *L, int i, ElemType *e)
{
	ElemType *p, *q;
	if (i < 1 || i > (*L).length)
		return ERROR;

	p = (*L).elem + i - 1;
	*e = *p;
	q = (*L).elem + (*L).length - 1;

	for (++p; p <= q; ++p)
		*(p--) = *p;

	(*L).length --;
	return OK;
}

Status ListTraverse(SqList L, void(*vi)(ElemType *))
{
	ElemType *p;
	int i;
	p = L.elem;
	for (i = 1; i <= L.length; i++)
		vi(p++);

	printf("\n");
	return OK;
}


Status equal(ElemType c1, ElemType c2)
{
	if (c1 == c2)
		return TRUE;
	return FALSE;
}

void Union(SqList *La, SqList Lb)
{
	ElemType e;
	int La_len, Lb_len;
	int i;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		if (!LocateElem(*La, e, equal))
			ListInsert(La, ++La_len, e);
	}
}
