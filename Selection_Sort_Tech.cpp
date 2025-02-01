#include<stdio.h>

void Selection_Sort(int arr[],int n){
	// The given array is divided into sorted and unsortedpart
	for(int i=0; i<n-1; i++){
		int min_ind=i;
		for(int j=i+1; j<n; j++){
			// identify the minimum index int unsorted part
			if(arr[min_ind]>arr[j]){
				min_ind=j;
			}
		}
		// swap the minimum element with i
		int temp=arr[i];
		arr[i]=arr[min_ind];
		arr[min_ind]=temp;
	}
}
int main(){
	int n;
	printf("Enter the Size of the Array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d Elements of the Array:\n",n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	Selection_Sort(arr,n);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
