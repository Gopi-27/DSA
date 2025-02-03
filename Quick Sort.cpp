#include<stdio.h>
void swap(int*,int*);
void QuickSort(int*,int ,int);
int Partion(int*,int ,int);
void swap(int *a,int *b){
	// interger changing the values at a and b
	int temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
int Partion(int arr[],int lb,int ub){
	// finding the correct place for the arr[lb] as loc
	// After that we need to Divide the array into two block
	// one block --> After the current loc+1 to upper
	// second block--> from the current lower tp loc-1 
	int start=lb;
	int end=ub;
	while(start<end){
	while(arr[start]<=arr[lb]){
		start++;
	}
	while(arr[end]>arr[lb]){
		end--;
	}
	if(start<end){
		swap(&arr[start],&arr[end]);
	}
}
	swap(&arr[lb],&arr[end]);
	return end;
}
void QuickSort(int arr[], int lb,int ub){
	if(lb<ub){
	int loc=Partion(arr,lb,ub);
		QuickSort(arr,lb,loc-1);
		QuickSort(arr,loc+1,ub);
	}
}
int main(){
	int n;
	printf("Enter The Size of the Array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d Elements of the Array:\n",n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	int lb=0;
	int ub=n-1;
	QuickSort(arr,lb,ub);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
