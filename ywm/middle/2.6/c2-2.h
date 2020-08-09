#pragma once
#define NAMELEN 16
#define CLASSLEN 10
struct stud
{
    char name[NAMELEN + 1];
    long num;
    char sex;
    int age;
    char Class[CLASSLEN + 1];
    int health;
    inline bool operator==(stud){return false;};
    inline bool operator<=(stud){return false;};
};
typedef struct stud ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};

typedef struct LNode *LinkList;

