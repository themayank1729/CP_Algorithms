#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int key, int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int n;
    int arr[1000];
    cout << "Enter the length of array ";
    cin >> n;
    cout << "enter " << n << " elements ";
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter the key element you want to find ";
    cin >> key;
    int result = binarySearch(arr, key, n);
    if (result == -1)
    {
        cout << endl
             << "element not found ";
    }
    else
    {
        cout << endl
             << "your element " << key << " is found at position " << result + 1;
    }
}