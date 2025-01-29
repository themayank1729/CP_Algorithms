#include <bits/stdc++.h>
using namespace std;
int maxRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    int element = -1;
    int NSE, PSE;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            element = st.top();
            st.pop();
            NSE = i;
            PSE = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        NSE = n;
        element = st.top();
        st.pop();
        PSE = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
    }
    return maxArea;
}
int main()
{
    vector<int> arr = {3, 2, 10, 11, 5, 10, 6, 3};
    cout << maxRectangleArea(arr);
}