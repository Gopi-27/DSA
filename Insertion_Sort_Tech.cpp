#include<stdio.h>
void InsertionSort(int arr[],int n){
	//separating the give array into sorted and unsorted part
	for(int i=1; i<n; i++){
		int val=arr[i];
		int idx=i-1;
		//pick the correct index to insert element in the sorted part
		for(int j=i-1; j>=0; j--){
		// shift the element at jth position to (j+1)th position
			if(arr[j]<val){
			idx=j+1;
			break;
			}
			arr[j+1]=arr[j];
			idx=j;
		}
		arr[idx]=val;	
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
	InsertionSort(arr,n);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
