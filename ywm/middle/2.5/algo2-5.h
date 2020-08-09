#pragma once
#include "c1.h"
#include "c2-2.h"

Status InitList(LinkList *L);
Status DestoryList(LinkList *L);
Status ClearList(LinkList L);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L, int i, ElemType *e);
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);
Status ListInsert(LinkList L, int i, ElemType e);
Status ListDelete(LinkList L, int i, ElemType *e);
Status ListTraverse(LinkList L, void(*vi)(ElemType));
void CreateList(LinkList *L, int n);
void CreateList2(LinkList *L, int n);
void MergeList(LinkList La, LinkList *Lb, LinkList *Lc);
void visit(ElemType c);