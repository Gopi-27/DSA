#include<stdio.h>
struct student
{
	char name[10];
	int roll_no;
};
int main()
{
	struct student s1;
	struct student s2;
	printf("enter the student 1 data:");
	scanf("%s",&s1.name);
	printf("etner the student roll no:");
	scanf("%d",&s1.roll_no);
	s2=s1;
	printf("student s2:%s\n",s2.name);
	printf("student s2 roll no:%d\n",s2.roll_no);
}

