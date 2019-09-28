////////header file////////

#pragma once
#include  <stdio.h>
#include  <stdlib.h>
#include"‘§∂®“Â.h"
//////////////////////////


////////type define////////

typedef int elemtype;

typedef struct single_link_list_node{
	elemtype data;
	single_link_list_node *next;
	}Single_Link_List_Node;

typedef struct single_link_list{
	Single_Link_List_Node *head, *tail;
	int length;
	}Single_Link_List;

//////////////////////////////
////////functions////////
