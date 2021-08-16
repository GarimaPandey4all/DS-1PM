#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i;

    for(i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > temp) // 10 > 3
        {
            arr[j + 1] = arr[j]; // ?, 10
            j = j - 1; // -1
        }

        arr[j + 1] = temp; // 3, 10
    }
}

int main()
{
    int arr[] = {10, 3, 7, 5, 2};
    int n = 5, i;

    insertionSort(arr, n);

    printf("Insertion Sorted:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
