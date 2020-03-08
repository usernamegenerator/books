#include <iostream>
using namespace std;

/*
Start at the beginning of an array and swap the first two elements 
if the first is bigger than the second. 
Go to the next pair, etc, continuously making sweeps of the array until sorted. O(n^2).
*/
void BubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j],arr[i]);
            }
        }
    }
}

int main()
{
    int arr[10] = {7, 8, 6, 9, 4, 3, 5, 2, 0, 1};
    BubbleSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}