#include <iostream>
#include <string.h>

using namespace std;

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

void bubbleSort(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSort(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print(int arr[], int size, char const *argv)
{
    if (strcmp(argv, "-a") == 0)
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

    if (strcmp(argv, "-d") == 0)
        for (int i = size - 1; i >= 0; i--)
            cout << arr[i] << " ";

    cout << endl;
}

void print(double arr[], int size, char const *argv)
{
    if (strcmp(argv, "-a") == 0)
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

    if (strcmp(argv, "-d") == 0)
        for (int i = size - 1; i >= 0; i--)
            cout << arr[i] << " ";

    cout << endl;
}

void print(string arr[], int size, char const *argv)
{
    if (strcmp(argv, "-a") == 0)
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

    if (strcmp(argv, "-d") == 0)
        for (int i = size - 1; i >= 0; i--)
            cout << arr[i] << " ";

    cout << endl;
}

int checkInt(int argc, char const *argv[])
{
    for (int i = 2; i < argc; i++)
        if (strspn(argv[i], "-0123456789") != strlen(argv[i]))
            return 0;
    return 1;
}

int checkDouble(int argc, char const *argv[])
{
    for (int i = 2; i < argc; i++)
        if (strspn(argv[i], ".-0123456789") != strlen(argv[i]))
            return 0;
    return 1;
}

void usage()
{
    cout << "Usage: ./foSort [-a|-d] [<integers>|<decimals>|<strings>]" << endl;
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

    if (checkInt(argc, argv))
    {
        int arr[size];
        for (int i = 0; i < size; i++)
            arr[i] = stoi(argv[i + argv_offset]);

        bubbleSort(arr, size);

        print(arr, size, argv[1]);
    }
    else if (checkDouble(argc, argv))
    {
        double arr[size];
        for (int i = 0; i < size; i++)
            arr[i] = stod(argv[i + argv_offset]);

        bubbleSort(arr, size);

        print(arr, size, argv[1]);
    }
    else
    {
        string arr[size];
        for (int i = 0; i < size; i++)
            arr[i] = (string)argv[i + argv_offset];

        bubbleSort(arr, size);

        print(arr, size, argv[1]);
    }

    return EXIT_SUCCESS;
}
