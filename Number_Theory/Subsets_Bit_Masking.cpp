#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset_cnt = (1 << n);
    vector<vector<int>> subsets;
    for (int mask = 0; mask < subset_cnt; mask++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    auto subsets = Subsets(v);
    for (auto sub : subsets)
    {
        for (int ele : sub)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
}
