#include<stdio.h>
int key;
int binarysearch(int [ ], int);
int main() {
    int i,a[30],n,k;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter the Key: ");
    scanf("%d",&key);
    k=binarysearch(a,n);
    if(k==-1)
        printf("Key is not found.");
    else
        printf("Key is found at %d index.",k);
}

int binarysearch(int a[], int n) {
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
