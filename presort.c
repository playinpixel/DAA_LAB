#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

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

void mergesort(int a[], int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a, low, mid, high);
	}
}


int eleUniqueness(int a[SIZE], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            return 0;
    }
    return 1;
}

int main()
{
    int i, size, flag;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);
	int low=0,high=size-1;
    mergesort(a,low,high);
	printf("The sorted array is: \n");
	for(i=0;i<size;i++)
		printf("%d",a[i]);
	printf("\n");
    flag = eleUniqueness(a, size);
    if (flag == 1)
        printf("The elements of the array are unique\n");
    else
        printf("The elements of the array are not unique\n");
    return 0;
}