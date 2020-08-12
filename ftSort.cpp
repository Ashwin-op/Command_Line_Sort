#include <iostream>
#include <string.h>

using namespace std;

template <class T>
void bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <class T>
void sortUtil(T arr[], int size, char const *argv)
{
    bubbleSort(arr, size);

    if (strcmp(argv, "-a") == 0)
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

    if (strcmp(argv, "-d") == 0)
        for (int i = size - 1; i >= 0; i--)
            cout << arr[i] << " ";

    cout << endl;
}

void usage()
{
    cout << "Usage: ./ftSort [-a/-d] [<integers>/<decimals>/<strings>]" << endl;
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

    if (strspn(argv[2], "0123456789") == strlen(argv[2]))
    {
        int arr[size];
        for (int i = 0; i < size; i++)
            arr[i] = stoi(argv[i + argv_offset]);

        sortUtil(arr, size, argv[1]);
    }
    else if (strspn(argv[2], ".0123456789") == strlen(argv[2]))
    {
        double arr[size];
        for (int i = 0; i < size; i++)
            arr[i] = stod(argv[i + argv_offset]);

        sortUtil(arr, size, argv[1]);
    }
    else
    {
        string arr[size];
        for (int i = 0; i < size; i++)
            arr[i] = (string)argv[i + argv_offset];

        sortUtil(arr, size, argv[1]);
    }

    return EXIT_SUCCESS;
}
