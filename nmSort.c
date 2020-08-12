#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
            arr[k++] = L[i++];
        else
            arr[k++] = M[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = M[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void usage()
{
    printf("Usage: ./nmSort [-a/-d] <integers>\n");
}

int main(int argc, char const *argv[])
{
    int argv_offset = 2;
    int size = argc - argv_offset;

    if (argc < 2)
    {
        usage();
        return EXIT_FAILURE;
    }

    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = atoi(argv[i + argv_offset]);

    mergeSort(arr, 0, size - 1);

    if (strcmp(argv[1], "-a") == 0)
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);

    if (strcmp(argv[1], "-d") == 0)
        for (int i = size - 1; i >= 0; i--)
            printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
