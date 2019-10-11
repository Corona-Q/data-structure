////////header file////////

#pragma once
#include  <stdio.h>
#include  <stdlib.h>
#include"‘§∂®“Â.h"
//////////////////////////


////////type define////////

typedef int ElemType;

typedef struct single_link_list_node{
	ElemType data;
	single_link_list_node *next;
	}SingleLinkListNode;

typedef struct single_link_list{
	SingleLinkListNode *head, *tail;
	int length;
	}SingleLinkList;

//////////////////////////////
////////functions////////
