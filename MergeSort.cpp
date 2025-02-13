#include<stdio.h>
void Merge(int *A,int start,int mid,int end){
	int i=start;
	int j=mid+1;
	int k=0;
	// Taking the extra array to merge the two sorted arrays
	int B[end-start+1];
	while(i<=mid && j<=end){
		if(A[i]>A[j]){
			B[k++]=A[j++];
		}else{
			B[k++]=A[i++];
		}
	}
	// if the elements in the first array are left add them into array-B
	while(i<=mid)B[k++]=A[i++];
	// if the elements in the second array are left add them into array-B 
	while(j<=end)B[k++]=A[j++];
	// rearranging the elements from B to the respective indices of A
	k=0;
	for(int i=start; i<=end; i++){
		A[i]=B[k++];
	}
	return;
}

void MergeSort(int *A,int start,int end){
	//base case
	if(start>=end){
		return;
	}
	// dividing the Array into two parts
	int mid=(start+end)/2;
	// sorting the first part of the array
	MergeSort(A,start,mid);
	//sorting the second part of the array
	MergeSort(A,mid+1,end);
	// Merging the two sorted arrys
	Merge(A,start,mid,end);
	return;
}

int main(){
	int n;
	printf("Enter the Size of the Array:\n");
	scanf("%d",&n);
	int A[n];
	printf("Enter %d Elements of the Array:\n",n);
	for(int i=0; i<n; i++){
		scanf("%d",&A[i]);
	}
	MergeSort(A,0,n-1);
	// printing the sorted Array
	for(int i=0; i<n; i++){
		printf("%d ",A[i]);
	}
	return 0;
}

