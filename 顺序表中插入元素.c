#include"sequence_list.h"
#include<time.h>
// ReSharper disable once CppUnusedIncludeDirective
#include "Ԥ����.h"

status Insert_Sql(SequenceList* L, int location,ElemType e);

void main(void)
{
	int num,up,low;
	int i;
	SequenceList L;
	Init_Sql(&L);
	srand((unsigned)time(0));
	printf("������˳�����Ԫ�ظ�����");
	scanf("%d", &num);
	printf("������Ҫ���ɵ����ֵķ�Χ��\n����Ϊ��");
	scanf("%d", &up);
	printf("����Ϊ��");
	scanf("%d", &low);
	for (i = 0; i < num; i++)
		Insert_Sql(&L, i, rand() % (up - low + 1) + low);
	printf("��������Ԫ�أ�");
	Ergodic_Sql(&L);
	getchar();
	getchar();
}
