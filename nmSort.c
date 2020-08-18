#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void usage()
{
    printf("Usage: ./nmSort [-a/-d] <integers>\n");
}

int main(int argc, char const *argv[])
{
    int argvOffset = 2;
    int size = argc - argvOffset;

    if (argc <= 2 || (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-d") != 0))
    {
        usage();
        return EXIT_FAILURE;
    }

    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = atoi(argv[i + argvOffset]);

    bubbleSort(arr, size);

    if (strcmp(argv[1], "-a") == 0)
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);

    if (strcmp(argv[1], "-d") == 0)
        for (int i = size - 1; i >= 0; i--)
            printf("%d ", arr[i]);

    printf("\n");

    return EXIT_SUCCESS;
}
