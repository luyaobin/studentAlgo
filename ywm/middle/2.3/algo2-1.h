#ifndef __ALGO2_1_H_
#define __ALGO2_1_H_
#include "c1.h"
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

Status InitList(SqList *L);
Status DestroyList(SqList *L);
Status ClearList(SqList *L);
Status ListEmpty(SqList L);
int ListLength(SqList L);
Status GetElem(SqList L, int i, ElemType * e);
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);
Status ListInsert(SqList *L, int i, ElemType e);
Status Delete(SqList *L, int i, ElemType *e);
Status ListTraverse(SqList L, void(*vi)(ElemType *));
void Union(SqList *La, SqList Lb);
void print(ElemType *c);
#endif