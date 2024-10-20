#include<stdio.h>
#include<stdlib.h>

void mergesort(int a[], int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a, low, mid, high);
	}
}

void merge(int a[], int low, int mid, int high){
	int i,j,k;
	int n1=mid-low+1;
	int n2=high-mid;
	int L[n1], R[n2];
	
	for(i=0;i<n1;i++){
		L[i]=a[low+i];
	}
	
	for(j=0;j<n2;j++){
		R[j]=a[mid+1+j];
	}

	i=0;
	j=0;
	k=low;
	
	while(i<n1&&j<n2){
		if(L[i]<=R[j]){
			a[k]=L[i];
			i++;
			k++;
		}
		else{
			a[k]=R[j];
			j++;
			k++;
		}
}

	while(i<n1){
			a[k]=L[i];
			i++;
			k++;

	}
	
	while(j<n2){
			a[k]=R[j];
			j++;
			k++;
	}
}

void print(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int n;
	printf("Enter the number of elements in the arrray. \n");
	scanf("%d",&n);
	int a[n],low=0,high=n-1;
	for(int i=0;i<n;i++){
		printf("Enter element %d \n",i+1);
		scanf("%d",&a[i]);
	}       
	printf("Array is: \n");
	print(a,n);
	mergesort(a,low,high);
	printf("The sorted array is: \n");
	print(a,n);
	return 0;
}