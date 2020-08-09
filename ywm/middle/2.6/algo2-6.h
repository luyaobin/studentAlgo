#pragma once
#include "c1.h"
#include "c2-2.h"
extern FILE *fp;
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
void InsertAscend(LinkList L, ElemType e);
void Print(struct stud e);
void Readin(struct stud *e);
void WriteToFIle(struct stud e);
Status ReadFromFile(struct stud *e);
Status FindFromNum(LinkList L, long num, LinkList *p, LinkList *q);
Status FindFromName(LinkList L, char name[], LinkList *p, LinkList *q);
Status DeleteElemNum(LinkList L, long num);
Status DeleteElemName(LinkList L, char name[]);
void Modify(ElemType *e);