#include <bits/stdc++.h>
using namespace std;
int longestSuccessiveElements(vector<int> &a)
{

    int n = a.size();
    if (n == 0)
        return 0;
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            cnt++;
            lastSmaller = a[i];
        }
        else if (lastSmaller != a[i])
        {
            lastSmaller = a[i];
            cnt = 1;
        }
        longest = max(longest, cnt);
    }
    return longest;
}
int longestSuccessiveElements(vector<int> &a)
{
    // Optimal Approach
    // time Complexity - O(2*N)
    int n = a.size();
    if (n == 0)
        return 0;
    unordered_set<int> st;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}