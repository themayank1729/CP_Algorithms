#include <bits/stdc++.h>
using namespace std;
vector<int> intersectionArray(const vector<int> &a, const vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> arr;
    while (i < n1 && j < n2)
    {
        if (a[i] == b[j])
        {
            if (arr.empty() || arr.back() != a[i])
            {
                arr.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return arr;
}
int main()
{
    vector<int> v1{1, 1, 2, 3, 4, 5, 5, 6};
    vector<int> v2{2, 2, 3, 4, 5};
    vector<int> v = intersectionArray(v1, v2);
    for (auto i : v)
    {
        cout << i << " ";
    }
}