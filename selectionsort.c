#include<stdio.h>
void selectionsort(int [ ], int);
int main() {
    int i,a[30],n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    selectionsort(a,n);
    printf("After sorting:\n");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
}

void selectionsort(int p[ ], int n) {
    int i,j,temp,minpos;
    for(i=0; i<n-1; i++)
    {
        minpos=i;
        for(j=i+1; j<n; j++)
            if(p[j]<p[minpos])
                minpos=j;
        temp=p[i];
        p[i]=p[minpos];
        p[minpos]=temp;
    }
}
