//This is my own code.

#include<stdlib.h>
#include<stdio.h>
#include"link list.h"
#include"sequence list.h"

typedef struct student
{
	int age;
	char name[30],gender[2];
	int num;
}stu;

int main()
{
	stu STU[3];
	printf("�������һ��С���ѵ����䣺");
	scanf("%d", &STU[0].age);
	printf("��һ��С���ѵ������ǣ�");
	printf("%d", STU[0].age);
	getchar();
	getchar();
	return 0;
}
