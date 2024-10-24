#include<stdio.h>
void bubbleSort(int a[],int n){
	int temp,swapped,i,j;
	for(i=0;i<n;i++){
		swapped=0;
		for(j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=1;
			}
		}
		if(!swapped){
			break;
		}
	}
}
void printArray(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	int a[10],n,i;
	printf("Program for bubble sort\n");
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the array elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bubbleSort(a,n);
	printf("Sorted array: ");
	printArray(a,n);
	return 0;
}
