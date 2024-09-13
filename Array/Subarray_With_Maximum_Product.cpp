#include <bits/stdc++.h>

int subarrayWithMaxProduct(vector<int> &arr)
{
    int ans = INT_MIN;
    int pre = 1, suf = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        suf = suf * arr[n - i - 1];
        pre = pre * arr[i];
        ans = max(ans, max(pre, suf));
    }
    return ans;
}