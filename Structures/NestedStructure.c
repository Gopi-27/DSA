// Structure contains another structuer as it's member
#include<stdio.h>
struct DOB{
    int day;
    int month;
    int year;
};
struct Student{
    int roll;
    char name[20];
    struct DOB dob;
};
int main(){
    // initializing the nested Structures
    
    // Way 1;
    struct Student s1 = {1,"Gopi",{27,03,2006}};

    // Way 2;
    struct Student s2 = {name:"Venkata Gopi",dob:{27,06,2003},roll: 5};

    // Accessing The innerstructure members through nested structure

    printf("Student 1 Details\n");
    printf("Mr. %s wearing the roll Number %d was born on %d %d %d\n",s1.name,s1.roll,s1.dob.day,s1.dob.month,s1.dob.year);
    printf("Student 2 Details\n");
    printf("Mr. %s wearing the roll Number %d was born on %d %d %d\n",s2.name,s2.roll,s2.dob.day,s2.dob.month,s2.dob.year);
    return 0;

}