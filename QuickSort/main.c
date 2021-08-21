#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int first, int last)
{
    int pivot, i, j, temp;

    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            while(arr[pivot] >= arr[i] && i < last)
            {
                i++;
            }

            while(arr[pivot] < arr[j])
            {
                j--;
            }

            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        //swapping of pivot value with j value
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        //Left sub array
        quickSort(arr, 0, j - 1);

        //Right sub array
        quickSort(arr, j + 1, last);
    }
}

int main()
{
    int arr[] = {10, 3, 7, 5, 2};
    int i;

    quickSort(arr, 0, 4);

    printf("Quick Sorted:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
