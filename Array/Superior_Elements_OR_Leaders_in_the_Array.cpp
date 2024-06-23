// Leaders in the array
#include <bits/stdc++.h>
using namespace std;
vector<int> superiorElements(vector<int> &a)
{
    // Time complexity - O(N) + O(N*log(N))

    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}