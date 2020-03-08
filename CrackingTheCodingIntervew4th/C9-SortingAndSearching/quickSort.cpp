/*
Quick Sort:
Pick a random element and partition the array, 
such that all numbers that are less than it come before all elements that are greater than it. 
Then do that for each half, then each quarter, etc. O(n log n) expected, O(n^2) worst case.
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
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
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

int main()
{
    int arr[] = {7, 8, 6, 9, 4, 3, 5, 2, 0, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    // cout << sizeof(arr) / sizeof(arr[0]) << endl;
    quicksort(arr, 0, arrSize - 1);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}