#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
    cout << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int size;
    cout << "enter size of array ";
    cin >> size;
    int arr[1000];
    cout << endl
         << "enter array elements  ";
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, size);
}