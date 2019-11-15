////////header file////////
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Ԥ����.h"
////////header file////////

////////#define////////////
#define ListSize 100
#define ListIncrement 10
////////type define////////
typedef int ElemType;
typedef struct sequence_list{
	ElemType *elem;
	int len;
	int listsize;
	}SequenceList;

////////function///////////
status Init_Sql(SequenceList *L)
{//��ʼ��һ���յ�˳���
	L->elem = (ElemType*)malloc(ListSize * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);//�洢����ʧ��
	L->len = 0;//�ձ�Ϊ0
	L->listsize = ListSize;//��ʼ�洢����
}

status Insert_Sql(SequenceList *L,int location,ElemType e)
{
	//��L��location����e
	ElemType *p, *q;
	if(location<0||location>L->len)//����λ�ò��Ϸ�
	{
		fprintf(stderr, "location��ֵ����Ŷ~");
			return ERROR;
	}
	if(L->listsize==L->len)//��������ռ�������Ҫ����
	{
		L->elem = (ElemType*)realloc(L->elem, (L->listsize + ListIncrement) * sizeof(ElemType));
		if (!L->elem) exit(OVERFLOW);
		else L->listsize += ListIncrement;
	}
	q = &(L->elem[location]);
	if(L->len>0)//�������Ҫ��
	for(p=&(L->elem[L->len-1]);p<=q;p++)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L->len++;//����1
	return OK;
}

void Ergodic_Sql(SequenceList*L)
{
	//���������˳���
	int i;
	for(i=0;i<L->len;i++)
		printf("%d ", L->elem[i]);
}

status Destroy_Sql(SequenceList *L)
{
	//����˳��� 
	free(L->elem);
	L->elem = NULL;//�������Ҫ����Ҫ©��Ŷ��
	L->len = 0;
	L->listsize = 0;
	return OK;
}

int Locate_Sql_Elem(SequenceList *list, ElemType element)
{
	//��˳���L�в��ҵ�1��ֵ��e���Ԫ�ص�λ��
	//����ҵ�������λ��ֵ�����û�ҵ�������infeasible
	int i,symbol=0;
	for(i=0;i<list->len;i++)
	{
		if (list->elem[i] == element) return i + 1;
		else symbol = 1;
	}
	if (symbol = 1) return INFEASIBLE;
}
	

//////////////////////////
