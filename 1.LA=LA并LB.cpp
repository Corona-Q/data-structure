//This is my own code.

#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include"link list.h"
#include"sequence list.h"

#define List_Length 20//���Ա���
#define List_Size 100//�����ռ��С


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
	srand((int)time(0));//�������������
	for(i=0;i<List_Length;i++)
	{
		LA.data[i] = rand() % List_Length + 1;
		LB.data[i] = rand() % List_Length + 1;
	}
	LA.len = LB.len = List_Length;
	printf("A��������ǣ�\n");
	for(i=0;i<LA.len;i++)
	{
		printf("%d ", LA.data[i]);
	}
	printf("\nB��������ǣ�\n");
	for (i = 0; i<LB.len; i++)
	{
		printf("%d ", LB.data[i]);
	}
	Union(&LA, &LB);
	printf("\nA���B��ϲ���ı�Ϊ��\n");
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
//���ұ����Ƿ���eԪ��
{
	int i;
    for(i=0;i<x;i++)
		if (GetElem(L, i) == e) return TRUE;
	 return FALSE;
    
}
void Union(List *LA,List *LB)
//�ϲ�
{
	int i;
	int alen = LA->len;//alen��L1�ĳ�ʼ����
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
//�ڱ�β����e
{
	L->data[L->len++] = e;
}