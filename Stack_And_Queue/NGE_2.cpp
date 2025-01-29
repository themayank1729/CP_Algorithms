#include <bits/stdc++.h>
using namespace std;
vector<int> betterApproach(vector<int> &arr)
{
    vector<int> nge;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool isPresent = false;
        for (int j = i + 1; j <= i + (n - 1); j++)
        {

            int ind = j % n;
            if (arr[ind] > arr[i])
            {
                nge.push_back(arr[ind]);

                isPresent = true;
                break;
            }
        }
        if (!isPresent)
        {
            nge.push_back(-1);
        }
    }
    return nge;
}
vector<int> MayankoptimalApproach(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    st.push(arr[0]);
    vector<int> nge;
    for (int i = n - 1; i >= 0; i--)
    {

        st.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= st.top())
        {
            st.pop();
        }
        if (!st.empty())
            nge.push_back(st.top());
        else
            nge.push_back(-1);
        st.push(arr[i]);
    }
    reverse(nge.begin(), nge.end());
    return nge;
}
vector<int> StriveroptimalApproach(vector<int> arr)
{
//Time complexity - O ( 4n)
    stack<int> st;
    int n = arr.size();
    st.push(arr[0]);
    vector<int> nge;
    
    for (int i = 2*n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i%n] >= st.top())
        {
            st.pop();
        }
        if(i<n)
        {
            if(st.empty())
            {
         nge.push_back(-1);
            }
            else
            {
                nge.push_back(st.top());
            }
        }
        st.push(arr[i%n]);
    }
       reverse(nge.begin(), nge.end());
    return nge;
}

int main()
{
    vector<int> nums = {5,4,3,2,1};
    vector<int> ans = betterApproach(nums);
    vector<int> ans2 = StriveroptimalApproach(nums);
    for (auto it : ans2)
    {
        cout << it << " ";
    }
}