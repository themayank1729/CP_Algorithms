#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> a, int b)
{
    int n = a.size();
    map<int, int> mpp;
    int subXR = 0, remainXor = 0;
    mpp[0] = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        subXR = subXR ^ a[i];
        remainXor = subXR ^ b;

        count += mpp[remainXor];

        mpp[subXR]++;
    }
    return count;
}