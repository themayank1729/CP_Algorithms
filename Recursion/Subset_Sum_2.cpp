#include <bits/stdc++.h>
using namespace std;

void findSubsets(vector<int> &v, int idx,
                 vector<int> &subset,
                 set<vector<int>> &result)
{
    if (!subset.empty())
        result.insert(subset);

    for (int j = idx; j < v.size(); j++)
    {

        subset.push_back(v[j]);
        findSubsets(v, j + 1, subset, result);
        subset.pop_back();
    }
}

vector<vector<int>> solve(vector<int> &v)
{

    set<vector<int>> result;
    vector<int> subset;
    findSubsets(v, 0, subset, result);

    vector<vector<int>> res;
    for (auto v : result)
        res.push_back(v);

    return res;
}

int main()
{
    vector<int> A = {1, 2, 2};
    vector<vector<int>> result = solve(A);
    for (auto v : result)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}