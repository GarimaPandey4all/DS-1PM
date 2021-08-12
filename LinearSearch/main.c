#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10], n, i, search;

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

    for(i = 0; i < n; i++)
    {
        if(arr[i] == search)
        {
            printf("Number is found at location: %d", i+1);
            break;
        }
    }

    if(i == n)
    {
        printf("Number is not found");
    }

    return 0;
}
