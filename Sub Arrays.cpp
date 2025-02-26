#include<stdio.h>
void PrintSubArrays(int *A,int start,int end,int n){
	if(start==n){
		return ;
	}
	if(end==n){
		PrintSubArrays(A,start+1,start+1,n);
		return ;
	}
	for(int i=start; i<=end; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	PrintSubArrays(A,start,end+1,n);
	return ;
}

int main(){
	int n;
	printf("Enter Size of the Array:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d Elements of the Array:\n",n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	PrintSubArrays(arr,0,0,n);
}
