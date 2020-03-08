/*
9.1 You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.
*/
#include <iostream>

using namespace std;

int partition(int *arr, int low, int high)
{
    int pivotValue = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (arr[i] < pivotValue)
        {
            i++;
        }
        while (arr[j] > pivotValue)
        {
            j--;
        }
        if (i > j)
        {
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
}

void mergeTwoSortedArray(int *arrA, int *arrB, int arrAsize, int arrAactualSize, int arrBsize)
{
    int i = arrAactualSize - 1;
    int j = arrBsize - 1;
    int k = arrAsize - 1;
    while (i >= 0 && j >= 0)
    {
        if (arrA[i] > arrB[j])
        {
            arrA[k--] = arrA[i--];
        }
        else
        {
            arrA[k--] = arrB[j--];
        }
    }

    while (j >= 0)
    {
        arrA[k--] = arrB[j--];
    }

    while (i >= 0)
    {
        arrA[k--] = arrA[i--];
    }
}

int main()
{
    int arrA[] = {7, 65, 6, 56, 4, 43, 5, 2, 0, 12, 99, 99, 99, 99, 99, 99};
    int arrB[] = {9, 98, 1, 3, 8, 24};
    int arrASize = sizeof(arrA) / sizeof(arrA[0]);
    int arrBSize = sizeof(arrB) / sizeof(arrB[0]);
    // cout << sizeof(arr) / sizeof(arr[0]) << endl;
    quicksort(arrA, 0, arrASize - 1);

    quicksort(arrB, 0, arrBSize - 1);

    for (int i = 0; i < arrASize; i++)
    {
        cout << arrA[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < arrBSize; i++)
    {
        cout << arrB[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < arrASize - arrBSize; i++)
    {
        cout << arrA[i] << " ";
    }
    cout << endl;

    cout << arrASize << " " << arrBSize << " " << arrASize - arrBSize << endl;
    mergeTwoSortedArray(arrA, arrB, arrASize, arrASize - arrBSize, arrBSize);

    for (int i = 0; i < arrASize; i++)
    {
        cout << arrA[i] << " ";
    }
    cout << endl;
}