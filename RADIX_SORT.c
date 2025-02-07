#include<stdio.h>
#include<math.h>
void RadixSort(int *, int );
int FindMax(int*,int );
int FindMax(int* arr,int n){
	int max=arr[0];
	for(int i=0; i<n; i++){
		if(max<arr[i]){
			max=arr[i];
		}
		
}
return max;
}
void RadixSort(int *arr,int n){
	int buc[10][n];
	int cnt[10]={0};
	int max=FindMax(arr,n);
	int dig=(int)log10(max)+1;// getting the number of digits  in the max number
	for(int i=1; i<=pow(10,dig); i*=10){
		//segregating into the buckets
		for(int j=0; j<n; j++){
			int pos=(arr[j]/i)%10;
			// for first iteration unit's place digit
			// for second iteration tenth place digit
			// for third iterartion hundered place digit and soo.....n
			buc[pos][cnt[pos]]=arr[j];
			cnt[pos]++;
		}
		// CONSTURCTING THE ARRAY
		int idx=0;
		for(int r=0; r<10; r++){
			for(int j=0; j<cnt[r]; j++){
				arr[idx]=buc[r][j];
				idx++;
			}
			cnt[r]=0;
		}
		
	}
}
int main(){
	int n;
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d Elements of the array\n",n);
	for(int i=0; i<n  ; i++){
		scanf("%d",&arr[i]);
	}
	RadixSort(arr,n);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}

