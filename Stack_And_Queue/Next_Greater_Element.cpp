#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans;
    ans.push_back(-1);
    stack<int> st;
    st.push(v.back());
    for (int i = n - 2; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= v[i])
        {
            st.pop();
        }
        if (!st.empty())
            ans.push_back(st.top());
        else
            ans.push_back(-1);

        st.push(v[i]);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int t = 1;
    /// cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}