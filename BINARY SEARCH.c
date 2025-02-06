#include <stdio.h> 
int binarySearch(int[],int,int);    
 
int binarySearch(int arr[], int n, int target){ 
    int low=0,high=n - 1; 
 
    while(low<=high){ 
        int mid = (low + high) / 2; 
 
         if (arr[mid] == target){ 
              return mid;      // Element found. 
         } 
         if (arr[mid] < target){ 
              low = mid + 1;     // Search in the right half. 
         }else{ 
              high = mid - 1;     // Search in the left half. 
         } 
      } 
    return -1;        // Element not found. 
} 
int main()  
{ 
    int i,key,n; 
    printf("Enter the Size of the Array\n"); 
    scanf("%d",&n); 
    int arr[n]; 
    for(i=0;i<n;i++) {
     scanf("%d",&arr[i]); 
    }
 printf("Enter the Key Element to search in the given array\n"); 
 scanf("%d",&key); 
  
 int index=binarySearch(arr,n,key); 
  
 if(index==-1) 
  printf("%d is not found in the given array",key); 
 else 
  printf("%d is found at %d index in the given array",key,index); 
  
 return 0; 
}
