#include <stdio.h>
#include<stdlib.h>
#include"Ԥ����.h"
#include"sequence_list.h"
#include <time.h>

void main()
{
	int elementNumber,upperLimit,lowerLimit;
	int i,element,location;
	char select[2];
	SequenceList list;
	Init_Sql(&list);
	srand((unsigned)time(0));
	printf("����������ɸ�˳���Ԫ�أ�������Ҫ���ɵ�˳���Ԫ�ظ�����");
	scanf("%d",&elementNumber);
	printf("����������Ԫ�����ޣ�");
	scanf("%d", &upperLimit);
	printf("����������Ԫ�����ޣ�");
	scanf("%d", &lowerLimit);
	for (i = 0; i < elementNumber; i++) Insert_Sql(&list, i, rand() % (upperLimit + lowerLimit + 1) + lowerLimit);
	printf("��������Ԫ��Ϊ��");
	Ergodic_Sql(&list);
	printf("\n�Ƿ�Ҫ����Ԫ�أ�(y/n)");
	scanf("%1s", select);//���ַ�������ʽ��ȡ����,����ֻ�洢һ���ֽ�!
	while(select[0]=='y'||select[0]=='Y')//����ط���while����Ϊ�����п���Ҫ�������ң�
	{
		printf("������Ҫ���ҵ�Ԫ�أ�");
		scanf("%d", &element);
		location = Locate_Sql_Elem(&list, element);
		if(location>=0)printf("\n�ҵ�Ŀ��Ԫ�أ�λ��Ϊ��%d\n", location);
		else printf("û���ţ�զ���أ�");
		printf("�ٲ�һ������y/n)");
		scanf("%1s", select);
	}
	printf("���������");
	Destroy_Sql(&list);
	system("pause");
}
