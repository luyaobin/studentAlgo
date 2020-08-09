#include <iostream>
#include "algo2-5.h"
using namespace std;
int main(int argc, char ** argv)
{
	int n = 5;
	LinkList La, Lb, Lc;
	printf("按非递减顺序");
	CreateList2(&La, n);

	printf("La = ");
	ListTraverse(La, visit);
	printf("按非递增顺序");

	CreateList(&Lb, n);
	printf("Lb = ");
	ListTraverse(Lb, visit);
	MergeList(La, &Lb, &Lc);
	printf("Lc = ");
	ListTraverse(Lc, visit);
}
