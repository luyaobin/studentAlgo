#include <iostream>
#include "algo2-6.h"
using namespace std;
#define N 4
int main(int argc, char ** argv)
{
	struct  stud student[N] = {
		{"王小林", 790631,'m', 18, "计 91", 0 },
		{"陈红"  , 790632,'f', 20, "计 91", 1 },
		{"刘建平", 790633,'m', 21, "计 91", 0 },
		{"张立立", 790634,'m', 17, "计 91", 2 }
	};
	int i, j, flag = 1;
	long num;
	char filename[13], name[NAMELEN + 1];
	ElemType e;
	LinkList T, p, q;
	InitList(&T);

	while (flag)
	{
		printf("1:将结体数组student中记录按学号非降序插入链表\n");
		printf("2:将文件中记录按学号非降序插入链表\n");
		printf("3:键盘输入新记录，并将其按学号非降序插入链表\n");
		printf("4:删除链表中第一个有给定学号的记录\n");
		printf("5:删除链表中第一个有给定姓名的记录\n");
		printf("6:修改链表中第一个有给定学号的记录\n");
		printf("7:修改链表中第一个有给定姓名的记录\n");
		printf("8:查找链表中第一个有给定学号的记录\n");
		printf("9:查找链表中第一个有给定姓名的记录\n");
		printf("10:显示所有记录 11：将链表中的所有记录存入文件 12：结束\n");

		printf("请选择操作命令：");
		scanf("%d", &i);
		switch (i)
		{
		case 1: {
			for (j = 0; j < N; j++)
				InsertAscend(T, student[j]);
			break;
		}
		case 2: {
			printf("请输入文件名:");
			scanf("%s",filename);
			if ((fp = fopen(filename, "rb")) == NULL)
				printf("打开文件失败！\n");
			else {
				while (ReadFromFile(&e))
				{
					InsertAscend(T, e);
				}
				fclose(fp);
			}
			break;
		}
		case 3: {
			Readin(&e);
			InsertAscend(T, e);
			break;
		}
		case 4: {
			printf("请输入待删除记录的学号：");
			scanf("%ld", &num);
			if (!DeleteElemNum(T, num))
				printf("没有学号为%ld 的记录\n", num);
			break;
		}
		case 5: {
			printf("请输入待删除记录的姓名:");
			scanf("%s", name);
			if (!DeleteElemName(T, name))
				printf("没有姓名为%s 的记录\n", name);
			break;
		}
		case 6: {
			printf("请输入待修改记录的学号:");
			scanf("%ld%*c", &num);
			if (!FindFromNum(T, num, &p, &q))
				printf("没有学号为%ld 的记录\n", num);
			else {
				Modify(&q->data);
				if (q->data.num != num) {
					p->next = q->next;
					InsertAscend(T, q->data);
					free(q);
				}
			}
			break;
		}
		case 7: {
			printf("请输入待修改记录的姓名:");
			scanf("%s%*c", name);
			if (!FindFromName(T, name, &p, &q))
				printf("没有姓名为%s 的记录\n", name);
			else {
				num = q->data.num;
				Modify(&q->data);
				if (q->data.num != num) {
					p->next = q->next;
					InsertAscend(T, q->data);
					free(q);
				}
			}
			break;
		}
		case 8: {
			printf("请输入待查找记录的学号:");
			scanf("%ld", &num);
			if (!FindFromNum(T, num, &p, &q))
				printf("没有学号为%ld的记录\n", num);
			else
				Print(q->data);
			break;
		}
		case 9: {
			printf("请输入待查找记录的姓名:");
			scanf("%s", name);
			if (!FindFromName(T, name, &p, &q))
				printf("没有姓名为%s的记录\n", name);
			else
				Print(q->data);
			break;
		}
		case 10: {
			printf("\t姓名\t学号\t性别\t年龄\t班级\t健康状况\n");
			ListTraverse(T, Print);
			break;
		}
		case 11: {
			printf("请输入文件名:");
			scanf("%s", filename);
			if ((fp = fopen(filename, "wb")) == NULL)
				printf("打开文件失败\n");
			else
				ListTraverse(T, WriteToFIle);
			fclose(fp);
			break;
		}
		case 12: flag = 0;
		default:
			break;
		}
	}
	
}
