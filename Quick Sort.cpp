#include<stdio.h>

int Partition(int *A,int key,int start,int end){
	int s=start;
	int e=end;
	while(s<e){
		// Getting the index of  first larger element than key from start
		while(s <= end && A[s]<=key)s++;
		// Getting the index of first smaller element than key from end
		while(A[e]>key)e--;
		
		if(s<e){
			// swapping the first larger element from start and first smaller element for end
			int temp=A[s];
			A[s]=A[e];
			A[e]=temp;
		}
	}
	// swapping the key and element at e index
	int temp=A[e];
	A[e]=key;
	A[start]=temp;
	// returning the index of pivot element
	return e;
	
}

void QuickSort(int *A,int start,int end){
	
	if(start<end){
		// taking the first element as pivot element
		int pivot=A[start];
		// function which can place the pivot element at correct place and returns it's index 
		// After Partition all the elements before the pivot element are smallerthan pivot element
		// and all the elements after the pivot element are greaterthan pivot element 
		int pidx=Partition(A,pivot,start,end);
		// Dividing the array into two parts
		// 1. from start to the before pivot element
		QuickSort(A,start,pidx-1);
		// 2. after the pivot element to end
		QuickSort(A,pidx+1,end);
		
		return;
		
		
	}
	
	return;
	
}
int main(){
	int n;
	printf("Enter the size of the Array:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d Elements of the Array:\n",n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,n-1);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
