#include<stdio.h>
struct Student{
    int roll;
    char name[20];
    char Clg[40];
}
int main(){
    // initilizing the Arrry of structures of size 3;
    struct Student Arr[3] = {{1,"Sitha","AUS"},{2,"Rama","ACET"},{3,"Lakshman","AEC"}};

    //Accessing Array of Structure members
    for(int i = 0; i < 3; i++){
        printf("Student %d Details\n",i + 1);
        printf("Roll Number : %d\n",Arr[i].roll);
        printf("Student Name : %s\n",Arr[i].name);
        printf("College Name : %s\n",Arr[i].Clg);
    }
    return;

}