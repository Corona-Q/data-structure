//This is my own code.

#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include"link list.h"
#include"sequence list.h"

#define List_Length 20//线性表长度
#define List_Size 100//向量空间大小


typedef struct list
{
	elemtype data[List_Size];
	int len;
}List;

void InsertElem(List *L, elemtype e);
void Union(List *L1, List *L2);
status LocateElem(List L, int x, elemtype e);
status LocateElem(List L, int x, elemtype e);
elemtype GetElem(List L, int i);

int main()
{
	List LA, LB;
	int i;
	srand((int)time(0));//生成随机数序列
	for(i=0;i<List_Length;i++)
	{
		LA.data[i] = rand() % List_Length + 1;
		LB.data[i] = rand() % List_Length + 1;
	}
	LA.len = LB.len = List_Length;
	printf("A表的数据是：\n");
	for(i=0;i<LA.len;i++)
	{
		printf("%d ", LA.data[i]);
	}
	printf("\nB表的数据是：\n");
	for (i = 0; i<LB.len; i++)
	{
		printf("%d ", LB.data[i]);
	}
	Union(&LA, &LB);
	printf("\nA表和B表合并后的表为：\n");
	for(i=0;i<LA.len;i++)
	{
		printf("%d ", LA.data[i]);
	}
	getchar();
	getchar();
	return 0;
}
elemtype GetElem(List L, int i)
{
	return L.data[i];
}
status LocateElem(List L,int x,elemtype e)
//查找表中是否有e元素
{
	int i;
    for(i=0;i<x;i++)
		if (GetElem(L, i) == e) return TRUE;
	 return FALSE;
    
}
void Union(List *LA,List *LB)
//合并
{
	int i;
	int alen = LA->len;//alen是L1的初始长度
	elemtype e;
	for (i = 0; i < LB->len; i++) {
		e = GetElem(*LB,i);
		if (!LocateElem(*LA, alen, e))
		{
			InsertElem(LA, e);
		}
	}
}
void InsertElem(List *L,elemtype e)
//在表尾插入e
{
	L->data[L->len++] = e;
}