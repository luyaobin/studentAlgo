#pragma once
typedef int ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};

typedef struct LNode *LinkList;

