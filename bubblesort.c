/*C Program that implements Bubble sort */
#include<stdio.h>
void bubblesort (int[], int);
void main()
{
    int a[50], i, n;
    printf("Enter n:");
    scanf("%d", &n);
    printf("Enter array elements:");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    bubblesort(a,n);
    printf("Sorted list\n");
    for(i=0; i<n; i++)
        printf("%5d", a[i]);
}
void bubblesort(int a[], int n)
{
    int i, j, temp;
    for(i=0; i<=(n-2); i++)
    {
        for(j=0; j<=(n-2-i); j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
