//#include<stdio.h>
//void printSubSeq(int A[],int idx,int n,int B[]){
//	
//	if(idx>=n){
//		for(int i=0; i<n; i++){
//			if(B[i]!=0){
//				printf("%d ",B[i]);
//			}
//		}
//		printf("\n");
//		return ;
//	}
//	
//	// picking
//	B[idx]=A[idx];
//	printSubSeq(A,idx+1,n,B);
//	B[idx]=0;
//	
//	// not picking 
//	
//	printSubSeq(A,idx+1,n,B);
//	
//}
//int main(){
//	int n;
//	printf("Enter the size of  Array:");
//	scanf("%d",&n);
//	int A[n];
//	printf("Enter %d elements of the Array:\n",n);
//	for(int i=0; i<n; i++){
//		scanf("%d",&A[i]);
//	}
//	int B[n];
//	printSubSeq(A,0,n,B);
//}



//
//#include<stdio.h>
//void BubbleSort(int arr[],int n,int idx){
//	if(idx==n){
//		return ;
//	}
//	
//	if(arr[idx-1]>arr[idx]){
//		int temp=arr[idx-1];
//		arr[idx-1]=arr[idx];
//		arr[idx]=temp;
//	}
//	
//	BubbleSort(arr, n, idx+1);
//	BubbleSort( arr, n-1,1);
//	
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	int A[n];
//	for(int i=0; i<n; i++){
//		scanf("%d",&A[i]);
//	}
//	BubbleSort(A,n,1);
//	for(int i=0; i<n; i++){
//		printf("%d ",A[i]);
//	}
//}

#include<stdio.h>
int main(){
	int n;
	int m;
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	int brr[m];
	for(int i=0; i<m; i++){
		scanf("%d",&brr[i]);
	}
	int crr[m+n];
	int aidx=0;
	int bidx=0;
	int cidx=0;
	int flag=0;
	for(int i=0; i<m+n; i++){
		cidx=i;
		if(aidx==n || bidx==m){
			if(aidx==n){
				flag=1;
			}else{
				flag=2;
			}
			break;
		}
		if( arr[aidx]<brr[bidx] ){
			crr[i]=arr[aidx];
			aidx++;
		}else{
			crr[i]=brr[bidx];
			bidx++;
		}
	}
	
	if(flag==1){
		for(int i=cidx; i<m+n; i++){
			crr[i]=brr[bidx];
			bidx++;
		}
	}else{
		for(int i=cidx; i<m+n; i++){
			crr[i]=arr[aidx];
			aidx++;
		}
	}
	
	for(int i=0; i<m+n; i++){
		printf("%d ",crr[i]);
	}
}













