/*
Selection Sort:
Find the smallest element using a linear scan and move it to the front.
Then, find the second smallest and move it, again doing a linear scan.
Continue doing this until all the elements are in place. O(n^2).
*/

#include <iostream>
using namespace std;

void SelectionSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[10] = {7, 8, 6, 9, 4, 3, 5, 2, 0, 1};
    SelectionSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}