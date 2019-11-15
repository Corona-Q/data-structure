#include"sequence_list.h"
#include<time.h>
// ReSharper disable once CppUnusedIncludeDirective
#include "预定义.h"

status Insert_Sql(SequenceList* L, int location,ElemType e);

void main(void)
{
	int num,up,low;
	int i;
	SequenceList L;
	Init_Sql(&L);
	srand((unsigned)time(0));
	printf("请输入顺序表中元素个数：");
	scanf("%d", &num);
	printf("请输入要生成的数字的范围：\n上限为：");
	scanf("%d", &up);
	printf("下限为：");
	scanf("%d", &low);
	for (i = 0; i < num; i++)
		Insert_Sql(&L, i, rand() % (up - low + 1) + low);
	printf("表中所有元素：");
	Ergodic_Sql(&L);
	getchar();
	getchar();
}
