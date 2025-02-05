#include <stdio.h> 
int linearSearch(int*,int,int);   
// Function to perform linear search 
int linearSearch(int arr[], int size, int target){ 
    for (int i=0; i<size; i++){ 
        if (arr[i] == target) { 
            return i;    
        } 
    } 
    return -1;      
} 
int main()  
{ 
    int size,target,result; 
 
    printf("Enter the size of the array: "); 
    scanf("%d", &size); 
 
    int arr[size]; 
    printf("Enter %d elements:\n", size); 
    for (int i=0; i<size; i++) { 
        scanf("%d",&arr[i]); 
    } 
 
    printf("Enter the element to search for: "); 
    scanf("%d", &target); 
 
    result = linearSearch(arr, size, target);   
 
    if (result != -1)  
    { 
        printf("Element found at index %d.\n", result); 
    }  
    else  
    { 
        printf("Element not found in the array.\n"); 
    } 
    return 0; 
} 
