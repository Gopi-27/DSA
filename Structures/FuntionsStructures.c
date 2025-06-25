#include<stdio.h>
struct Student{
    int roll;
    char name[20];
    float CGPA;
};

void CallbyValue(struct Student s){
    s.CGPA = 10.0;
    return;
}
void CallbyReference(struct Student* s){
    s->CGPA = 10.0;
    return;
}
int main(){
    struct Student s1 = {21,"Gopi",9.6};
    struct Student s2 = {27,"Venkata Gopi",9.8};

    printf("Call by Value\n");
    printf("s1 Details Before Call by Value function\n");
    printf("Roll Number : %d \nName : %s \nCGPA : %f\n",s1.roll,s1.name,s1.CGPA);
    // Call by Value Function Call;
    CallbyValue(s1);
    printf("s1 Details After Call by Value function\n");
    printf("Roll Number : %d \nName : %s \nCGPA : %f\n",s1.roll,s1.name,s1.CGPA);
    printf("---------------------------------------------------------\n");
    printf("---------------------------------------------------------\n");
    printf("Call by Reference\n");
    printf("s2 Details Before Call by Reference function\n");
    printf("Roll Number : %d \nName : %s \nCGPA : %f\n",s1.roll,s2.name,s2.CGPA);
    // Call by Reference Function Call;
    CallbyReference(&s2);
    printf("s2 Details After Call by Reference function\n");
    printf("Roll Number : %d \nName : %s \nCGPA : %f\n",s2.roll,s2.name,s2.CGPA);
    printf("---------------------------------------------------------\n");
    return 0;
    

     
}