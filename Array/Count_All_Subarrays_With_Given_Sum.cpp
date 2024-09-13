#include <bits/stdc++.h>
int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum] += 1;
    }
    return count;
}