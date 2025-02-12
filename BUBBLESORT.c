#include<stdio.h>
void BubbleSort(int* arr,int n){
	for(int i=0; i<n-1; i++){
		for(int j=1; j<n-i; j++){
			// Checking the adajecent elements 
			// If they are not in correct order swap them
			if(arr[j-1]>arr[j]){
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	return;
}
int main(){
	int n;
	printf("Enter size of the of the array:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d Elements of the array\n",n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	BubbleSort(arr,n);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}

