#include <bits/stdc++.h>
using namespace std;
vector<int> alternateNumbers(vector<int> &a)
{
    // Tiime complexity - O(N)
    // space complexity - O(N)
    //  an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
    int n = a.size();
    vector<int> ans(n, 0);
    int negIndex = 1;
    int posIndex = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            ans[negIndex] = a[i];
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = a[i];
            posIndex += 2;
        }
    }
    return ans;
}