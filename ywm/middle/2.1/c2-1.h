#ifndef _C_2_1_H_
#define _C_2_1_H_
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

#endif // _C_2_1_H_
