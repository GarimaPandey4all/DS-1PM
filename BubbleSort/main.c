#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    //64, 34, 25, 12, 11, 90
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 11, 90};
    int i;

    bubbleSort(arr, 6);

    printf("Bubble Sorted:\n");
    for(i = 0; i < 6; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
