#include <stdio.h>
#include<stdlib.h>
#include"预定义.h"
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
	printf("随机生成若干个顺序表元素，请输入要生成的顺序表元素个数：");
	scanf("%d",&elementNumber);
	printf("请输入生成元素上限：");
	scanf("%d", &upperLimit);
	printf("请输入生成元素下限：");
	scanf("%d", &lowerLimit);
	for (i = 0; i < elementNumber; i++) Insert_Sql(&list, i, rand() % (upperLimit + lowerLimit + 1) + lowerLimit);
	printf("表中所有元素为：");
	Ergodic_Sql(&list);
	printf("\n是否要查找元素？(y/n)");
	scanf("%1s", select);//以字符串的形式读取数据,但是只存储一个字节!
	while(select[0]=='y'||select[0]=='Y')//这个地方用while，因为后面有可能要继续查找！
	{
		printf("请输入要查找的元素：");
		scanf("%d", &element);
		location = Locate_Sql_Elem(&list, element);
		if(location>=0)printf("\n找到目标元素，位序为：%d\n", location);
		else printf("没找着，咋整呢？");
		printf("再查一个？（y/n)");
		scanf("%1s", select);
	}
	printf("程序结束！");
	Destroy_Sql(&list);
	system("pause");
}
