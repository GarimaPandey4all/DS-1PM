#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10], n, i, search, first, last, middle;

    printf("Enter number of elements:");
    scanf("%d", &n);

    printf("Enter values in an Array:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Values in an Array are:");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    printf("\nEnter any value to be search:");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while(first <= last)
    {
        if(arr[middle] == search)
        {
            printf("Value found");
            break;
        }
        else if(arr[middle] < search)
        {
            first = middle + 1;
        }
        else if(arr[middle] > search)
        {
            last = middle - 1;
        }

        middle = (first + last) / 2;
    }

    if(first > last)
    {
        printf("Value is not found");
    }

    return 0;
}
