#include <bits/stdc++.h>
using namespace std;
vector<int> rotatedSort(vector<int> v1, int D)
{
    // most optimal approach
    // time complexity-- O(D)+O(n-D)+O(n);
    // space complexity -- O(1)
    reverse(v1.begin(), v1.begin() + D);
    reverse(v1.begin() + D, v1.end());
    reverse(v1.begin(), v1.end());
    return v1;
}
int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2 = rotatedSort(v1, 3);
    for (vector<int>::iterator it = v2.begin(); it < v2.end(); it++)
    {
        cout << *it << " ";
    }
}