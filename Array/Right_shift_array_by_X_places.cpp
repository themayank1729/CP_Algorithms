#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    x %= n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = arr[(i - x + n) % n];
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solution();
    return 0;
}
