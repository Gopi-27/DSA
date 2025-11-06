//
#include<stdio.h>
struct student
{
	char name[50];
	int marks[3];
	float total;
};
int main(int argc,char *argv[])
{
	int i;
	if(argc!=5){
		printf("usage:%s <student name> <mark1> <mark2> <mark3>\n",argv[0]);
		return 1;
	}
	struct student student;
	snprintf(student.name,sizeof(student.name),"%s",argv[1]);
	//read marks from command line//
	student.total=0;
	for(i=0;i<3;i++)
	{
		student.marks[i]=atoi(argv[i+2]);//converting string into int//
		student.total+=student.marks[i];
	}
	printf("\n student details:\n");
	printf("name:%s\n",student.name);
	printf("marks:%d %d %d\n",student.marks[0], student.marks[1], student.marks[2]);
	printf("total marks:%.2f\n",student.total);
	 return 0;
}
