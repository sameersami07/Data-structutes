/*C Program to perform Linear Search*/
#include<stdio.h>
int linearsearch(int [], int, int);
int main()
{
    int a[20], i, n, key, pos;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    pos = linearsearch(a, n, key);
    if(pos==-1)
        printf("Search is unsuccessful");
    else
        printf("Key is found at index: %d",pos);
    return 0;
}
int linearsearch(int a[], int n, int key)
{
    int i;
    for(i=0; i<n; i++)
        if(a[i]==key)
            return i;
    return -1;
}

 
