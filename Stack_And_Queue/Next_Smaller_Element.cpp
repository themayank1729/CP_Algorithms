#include <bits/stdc++.h>
using namespace std;
vector<int> optimalApproach(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
     vector<int>nge;
    for (int i = 0; i <n; i++)
    {
        while (!st.empty() && arr[i] <= st.top())
        {
            st.pop();
        }
        if (!st.empty())
            nge.push_back(st.top());
        else
            nge.push_back(-1);
        st.push(arr[i]);
    }
   // reverse(nge.begin(), nge.end());
    return nge;
}

int main()
{
    vector<int> nums = {5,7,9,6,7,4,5,1,3,7};
vector<int> ans = optimalApproach(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}