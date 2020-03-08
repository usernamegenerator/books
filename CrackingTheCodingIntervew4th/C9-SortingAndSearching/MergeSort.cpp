/*
Merge Sort:
Sort each pair of elements. Then, sort every four elements by merging every two pairs.
Then, sort every 8 elements, etc. O(n log n) expected and worst case.
*/
#include <iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    if (low >= high)
        return;
    cout << low << " " << mid << " " << high << ":" << arr[low] << " " << arr[mid] << " " << arr[high] << endl;
    int lowerSize = mid - low + 1;
    int higherSize = high - mid;
    int *lower = new int[lowerSize];
    int *higher = new int[higherSize];
    for (int i = 0; i < lowerSize; i++)
    {
        lower[i] = arr[low + i];
    }

    for (int i = 0; i < higherSize; i++)
    {
        higher[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = low;
    while (i < lowerSize && j < higherSize)
    {
        if (lower[i] < higher[j])
        {
            arr[k++] = lower[i++];
        }
        else
        {
            arr[k++] = higher[j++];
        }
    }

    while (i < lowerSize)
    {
        arr[k++] = lower[i++];
    }

    while (j < higherSize)
    {
        arr[k++] = higher[j++];
    }

    delete lower;
    delete higher;
}

void MergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {7, 8, 6, 9, 4, 3, 5, 2, 0, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    // cout << sizeof(arr) / sizeof(arr[0]) << endl;
    MergeSort(arr, 0, arrSize - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}