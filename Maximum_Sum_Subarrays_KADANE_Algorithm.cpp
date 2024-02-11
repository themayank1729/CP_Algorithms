#include <bits/stdc++.h>
using namespace std;
int maxSumSubarray(int arr[], int size)
{
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
        if (max_sum < sum)
            max_sum = sum;
        if (sum < 0)
            sum = 0;
    }
    return max_sum;
}
int main()
{
    int n;
    cout << "enter the length of array ";
    cin >> n;
    int arr[1000];
    cout << endl
         << "enter " << n << " elements ";
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "Maximum aubarray sum is : " << maxSumSubarray(arr, n);
}