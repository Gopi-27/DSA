//     Structure : 
// ->  It is a user-defined data type,it groups the different possibly different data types 
//     into single data type.
// ->  It can be declare using 'struct' key word.

#include<stdio.h>
// Create our own data type
struct car {
    char fuelType[20];
    float fuelCapacity;
    double cityMileage;
};

int main(){
    // Initializing 
    // It can be done in two ways

    // Way 1:
    struct car car1 = {"Petrol",1000.5,80};
    
    // Way 2:
    struct car car2 = {cityMileage: 90, fuelType: "Disel", fuelCapacity: 1200};

    // Accessing The Structure Memebers
    // member can be accessed using '.' (dot) operator

    printf("Details\n");
    printf("Car 1 fuel Type is : %s\n",car1.fuelType);
    printf("Car 1 fuel Capacity is : %f litres\n",car1.fuelCapacity);
    printf("Car 1 City Meleage is : %lf kilometers/hour\n",car1.cityMileage);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Car 2 fuel Type is : %s\n",car2.fuelType);
    printf("Car 2 fuel Capacity is : %f litres\n",car2.fuelCapacity);
    printf("Car 2 City Meleage is : %lf kilometers/hour\n",car2.cityMileage);
    printf("----------------------------------------------------------------------------------------\n");
    // Size of The Structure is sum of sizes of all members
    printf("The Size of Sturcture car1 is %d Bytes\n",sizeof(car1));
    return 0;

}
