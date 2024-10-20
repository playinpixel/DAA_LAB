#include <stdio.h>

void heapify(int a[], int n)
{
    int i,j,k,v,flag;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        flag=0;
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                    j++;
                
            }
            if(v>=a[j])
                flag=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}

void heapsort(int a[], int n)
{
    int i, temp;
    heapify(a,n);
    for(i=n;i>=2;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(a,i-1);
    }
}

int main()
{
    int a[100],n,i;
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    printf(" \nThe sorted array is:");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}