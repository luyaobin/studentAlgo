#include "c1.h"
#include "c2-2.h"
#include <stdio.h>
#include <cstdio>
char sta[3][16] = {u8"健康", u8"一般", u8"神经衰弱"};
FILE *fp;

Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(struct LNode));
    if (!*L)
        exit(OVERFLOW);
    
    (*L)->next = nullptr;
    return OK;
}

Status DestoryList(LinkList *L)
{
    LinkList q;
    while (*L)
    {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
    return OK;
}

Status ClearList(LinkList L)
{
    LinkList p,q;
    p = L->next;
    while (p)
    {
        q = p->next;
        free(q);
        p = q;
    }
    L->next = nullptr;
    return OK;
}

Status ListEmpty(LinkList L)
{
    if (L->next)
        return FALSE;
    return TRUE;
}

int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 1;
    LinkList p = L->next;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    
    if (!p || j > i)
        return ERROR;
    *e = p->data;

    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;
    LinkList p = L->next;
    while (p)
    {
        i++;
        if (compare(p->data, e))
            return i;
        p = p->next;
    }

    return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList q, p = L->next;
    while (p->next)
    {
        q = p->next;
        if (q->data == cur_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L->next;
    while (p->next)
    {
        if (p->data == cur_e)
        {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList p = L, s;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i - 1)
        return ERROR;

    s = (LinkList)malloc(sizeof(struct LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L, int i, ElemType *e)
{
    int j = 0;
    LinkList p = L, q;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (!p->next || j > i - 1)
        return ERROR;
    
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

Status ListTraverse(LinkList L, void(*vi)(ElemType))
{
    LinkList p = L->next;
    while (p)
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;    
}

void CreateList(LinkList *L, int n)
{
    int i;
    LinkList p;
    *L = (LinkList)malloc(sizeof(struct  LNode));
    (*L)->next = nullptr;
    printf("请输入%d个数据\n", n);
    for (i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateList2(LinkList *L, int n)
{
    int i;
    LinkList p, q;
    *L = (LinkList)malloc(sizeof(struct LNode));
    (*L)->next = nullptr;
    q = *L;
    printf("请输入%d个数据\n", n);
    for (i = 1; i <= n; ++i)
    {
        p = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &p->data);
        q->next = p;
        q = q->next;
    }
    p->next = nullptr;
}

void MergeList(LinkList La, LinkList *Lb, LinkList *Lc)
{
    LinkList pa = La->next, pb = (*Lb)->next, pc;
    *Lc = pc = La;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }        
    }
    pc ->next = pa ? pa : pb;
    free(*Lb);
    Lb = nullptr;
}

void visit(ElemType c)
{
    printf("%d", c);
}

void InsertAscend(LinkList L, ElemType e)
{
    LinkList q = L, p = L->next;
    while (p && e.num > p->data.num)
    {
        q = p;
        p = p->next;
    }
    
    q->next = (LinkList)malloc(sizeof(struct LNode));
    q->next->data = e;
    q->next->next = p;
}

void Print(struct stud e)
{
    printf("%-16s\t%6ld", e.name, e.num);
    if (e.sex == 'm')
        printf("\t男");
    else
        printf("\t女");
    printf("\t%5d\t%-4s", e.age, e.Class);
    printf("\t%16s\n", sta[e.health]);
}

void Readin(struct stud *e)
{
    printf("请输入姓名(<=%d 个字符)", NAMELEN);
    scanf("%s", e->name);
    printf("请输入学号:");
    scanf("%ld", &e->num);
    printf("请输入性别(m：男 f：女)");
    scanf("%*c%c", &e->sex);
    printf("请输入年龄：");
    scanf("%d", &e->age);
    printf("请输入班级(<=%d 个字符):", CLASSLEN);
    scanf("%s", e->Class);
    printf("请输入健康状况(0:%s 1:%s 2:%s)", sta[0], sta[1], sta[2]);
    scanf("%d", &e->health);
}

void WriteToFIle(struct stud e)
{
    fwrite(&e, sizeof(struct stud), 1, fp);
}

Status ReadFromFile(struct stud *e)
{
    int i;
    i = fread(e, sizeof(struct stud), 1, fp);
    if (i == 1)
        return OK;
    else
        return ERROR;
}

Status FindFromNum(LinkList L, long num, LinkList *p, LinkList *q)
{
    *p = L;
    while (*p)
    {
        *q = (*p)->next;
        if (*q && (*q)->data.num > num)
            break;
        
        if (*q && (*q)->data.num > num)
            return TRUE;
        *p = *q;
    }
    return FALSE;
}

Status FindFromName(LinkList L, char name[], LinkList *p, LinkList *q)
{
    *p = L;
    while (*p)
    {
        *q = (*p)->next;
        if (*q && !strcmp((*q)->data.name, name))
            return TRUE;
        *p = *q;
    }
    return FALSE;
}

Status DeleteElemNum(LinkList L, long num)
{
    LinkList p, q;
    if (FindFromNum(L, num, &p, &q))
    {
        p->next = q->next;
        free(q);
        return TRUE;
    }
    return FALSE;
}

Status DeleteElemName(LinkList L, char name[])
{
    LinkList p, q;
    if (FindFromName(L, name, &p, &q)) {
        p->next = q->next;
        free(q);
        return TRUE;
    }
    return FALSE;
}

void Modify(ElemType *e)
{
    char s[80];
    Print(*e);
    printf("请输入待修改项的内容，不修改的项按回车键保持原值：\n");
    printf("请输入姓名(<=%d 个字符)：", NAMELEN);
    scanf("%s", s);
    if (strlen(s))
        strcpy(e->name, s);
    printf("请输入学号:");
    scanf("%s", s);
    if (strlen(s))
        e->num = atoi(s);
    printf("请输入性别(m:男 f:女):");
    scanf("%s", s);
    if (strlen(s))
        e->sex = s[0];
    printf("请输入年龄:");
    scanf("%s", s);
    if (strlen(s))
        e->age = atoi(s);
    printf("请输入班级(<=%d 个字符):", CLASSLEN);
    scanf("%s", s);
    if (strlen(s))
        strcpy(e->Class, s);
    printf("请输入健康状况(0:%s 1:%s 2:%s)", sta[0], sta[1], sta[2]);
    scanf("%s", s);
    if (strlen(s))
        e->health = atoi(s);
}