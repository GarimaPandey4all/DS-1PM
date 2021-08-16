#include <stdio.h>
#include <stdlib.h>

void mergeort(int arr[], int n)
{
    int temp[n];

    for(int size = 1; size < n; size = size * 2)
    {
        int l1 = 0;
        int k = 0; // index for temp array

        while(l1 + size < n)
        {
            int h1 = l1 + size - 1; // 0
            int l2 = h1 + 1; // 1
            int h2 = l2 + size - 1; // 1, 8 + 8 - 1 = 15

            if(h2 >= n)
            {
                h2 = n - 1; // 9 - 1 = 8
            }

            //merge two pairs
            int i = l1; // 0
            int j = l2; // 1

            while(i <= h1 && j <= h2)
            {
                if(arr[i] <= arr[j])
                {
                    temp[k++] = arr[i++];
                }
                else {
                    temp[k++] = arr[j++];
                }
            }

            while(i <= h1) // 1 //false
            {
                temp[k++] = arr[i++];
            }
            while(j <= h2) // 1 <= 1
            {
                temp[k++] = arr[j++]; // k = 2
            }

            //merge completed

            l1 = h2 + 1;

        }

        //any pair left
        for(int i = l1; i < n; i++)
        {
            temp[k++] = arr[i];
        }

        for(int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }

        printf("\nSize of %d elements are:\n", size);
        for(int i = 0; i < n; i++)
        {
            printf("%d  ", arr[i]);
        }

    }
}


int main()
{
    int arr[] = {11, 22, 44, 33, 11, 66, 55, 88, 77};
    int n = 9, i;

    mergeort(arr, n);

    printf("\nMerge Sorted:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
