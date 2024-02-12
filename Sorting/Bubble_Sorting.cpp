#include <iostream>
using namespace std;
void BubbleSort(int arr[], int size)
{
    bool swapped = false;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == true)
        {
            break;
        }
    }
    cout << endl
         << "Sorted elements are :";
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements you want to sort :";
    cin >> n;
    int arr[10000];
    cout << endl
         << "Enter " << n << " elements ";
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BubbleSort(arr, n);
}