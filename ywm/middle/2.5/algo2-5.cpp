#include "c2-2.h"
#include "c1.h"

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