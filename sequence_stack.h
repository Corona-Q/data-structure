#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100//定义向量空间初始分配量
#define stack_increment 10//定义向量空间的分配增量
typedef int elementType;
typedef struct {
	elementType *baseAddress;
	elementType *topAddress;
	int stackSize;
}sequenceStack;
void visit(elementType e) {
	printf("%c", e);
}
sequenceStack *InitSequenceStack(sequenceStack *S) {
	if (!S) {
		S = (sequenceStack*)malloc(sizeof(sequenceStack));
		if (!S) return 0;
	}
	S->baseAddress = (elementType*)malloc(stack_init_size * sizeof(elementType));
	if (!S->baseAddress) return 0;
	S->topAddress = S->baseAddress;
	S->stackSize = stack_init_size;
	return S;
}