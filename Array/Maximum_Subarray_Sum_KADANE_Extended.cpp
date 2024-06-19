#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(vector<int> arr, int n)
{
    int start = 0, ansStart = -1, ansEnd = -1;
    long long sum = 0;
    long long max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            ansStart = start;
            ansEnd = i;
        }
    }
    if (max_sum > 0)
        return max_sum;
    else
        return 0;
}
int main()
{
}