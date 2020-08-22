#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascending(int a, int b)
{
    return a > b;
}
int descending(int a, int b)
{
    return b > a;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/************************************************************************************
This tells bubbleSort to expect a parameter (compare) that’s a pointer to a function
that receives two integer parameters and returns an integer result. Parentheses are
needed around *compare to group the * with compare to indicate that compare is a
pointer. If we had not included the parentheses, the declaration would have been
                        int *compare( int a, int b )
which declares a function that receives two integers as parameters and returns a 
pointer to an integer.
************************************************************************************/
int bubbleSort(int arr[], int size, int (*compare)(int a, int b))
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if ((*compare)(arr[j], arr[j + 1]))
                swap(&arr[j], &arr[j + 1]);
}

void usage()
{
    printf("Usage: ./fpSort [-a|-d] <integers>\n");
}

int main(int argc, char const *argv[])
{
    int argv_offset = 2;
    int size = argc - argv_offset;

    if (argc <= 2 || (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-d") != 0))
    {
        usage();
        return EXIT_FAILURE;
    }

    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = atoi(argv[i + argv_offset]);

    if (strcmp(argv[1], "-a") == 0)
        bubbleSort(arr, size, ascending);

    if (strcmp(argv[1], "-d") == 0)
        bubbleSort(arr, size, descending);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return EXIT_SUCCESS;
}
