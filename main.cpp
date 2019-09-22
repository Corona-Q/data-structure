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
	printf("请输入第一个小朋友的年龄：");
	scanf("%d", &STU[0].age);
	printf("第一个小朋友的年龄是：");
	printf("%d", STU[0].age);
	getchar();
	getchar();
	return 0;
}
