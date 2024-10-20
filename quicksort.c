#include <stdio.h>
#define SIZE 10

void swap(int *a, int *b)
{
    int temp =*a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot && i<=high-1)
        {
            i++;
        }

        while(a[j]>pivot && j>=low+1)
        {
            j--;
        }

        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}

void quicksort(int a[], int low, int high)
{
    if(low<high)
    {
        int partitionIndex=partition(a,low,high);
        quicksort(a,low,partitionIndex-1);
        quicksort(a,partitionIndex+1,high);
    }
}

int main()
{
    int a[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        printf("Enter %d elements:",i);
        scanf("%d",&a[i]);
    }
    printf("Original array:\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",a[i]);
    }
    quicksort(a,0,SIZE-1);
    printf("Sorted array:");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}