////////header file////////
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"预定义.h"
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
{//初始化一个空的顺序表
	L->elem = (ElemType*)malloc(ListSize * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);//存储分配失败
	L->len = 0;//空表长为0
	L->listsize = ListSize;//初始存储容量
}

status Insert_Sql(SequenceList *L,int location,ElemType e)
{
	//在L的location插入e
	ElemType *p, *q;
	if(location<0||location>L->len)//插入位置不合法
	{
		fprintf(stderr, "location的值不对哦~");
			return ERROR;
	}
	if(L->listsize==L->len)//如果向量空间满了需要扩容
	{
		L->elem = (ElemType*)realloc(L->elem, (L->listsize + ListIncrement) * sizeof(ElemType));
		if (!L->elem) exit(OVERFLOW);
		else L->listsize += ListIncrement;
	}
	q = &(L->elem[location]);
	if(L->len>0)//这里很重要！
	for(p=&(L->elem[L->len-1]);p<=q;p++)
	{
		*(p + 1) = *p;
	}
	*q = e;
	L->len++;//表长加1
	return OK;
}

void Ergodic_Sql(SequenceList*L)
{
	//遍历并输出顺序表
	int i;
	for(i=0;i<L->len;i++)
		printf("%d", L->elem[i]);
}

//////////////////////////
