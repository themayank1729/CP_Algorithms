#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
vector<int> findNSE(vector<int> &arr)
{
    vector<int> nse(arr.size());
    stack<int> st;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(arr[i]);
    }
    
    return nse;
}
vector<int> findPSEE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> psee(arr.size());
    ;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    
    return psee;
}
int optimalMinimumsSum(vector<int> &arr)
{
    int sum = 0;
    int n = arr.size();
    vector<int> NSE = findNSE(arr);
    vector<int> PSEE = findPSEE(arr);
    for (int i = 0; i < n; i++)
    {
        int left = i - PSEE[i];
        int right = NSE[i] - i;
        sum = sum + ((left * 1ll * right) * (arr[i])) % N;
    }
    return sum;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << optimalMinimumsSum(arr) << '\n';
}