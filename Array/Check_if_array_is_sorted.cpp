#include <bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> v1)
{
    for (int i = 0; i < v1.size() - 1; i++)
    {
        if (v1[i + 1] < v1[i])
            return false;
    }
    return true;
}
int main()
{
    int n;
    // cout << "enter length of array :";
    // cin >> n;
    cout << endl;
    vector<int> v1;
    vector<int> v2{1, 2, 3, 4, 6, 5, 7, 8, 9};
    int a;
    // for (int i = 0; i < n; i++)
    //{
    //    cin >> a;
    //   v1.push_back(a);
    // }
    if (isSorted(v2) == 1)
        cout << endl
             << "array is sorted ";
    else
        cout << "array is not sorted ";
}