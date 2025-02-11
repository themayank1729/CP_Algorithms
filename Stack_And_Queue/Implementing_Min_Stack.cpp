#include <bits/stdc++.h>
using namespace std;
class BruteStack
{
    stack<pair<int, int>> st;
    void push(int val)
    {
        if (!st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }
};
class MinStackOptimal
{
private:
    stack<int> st;
    int mini = INT_MAX;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else if (val >= mini)
        {
            st.push(val);
        }
        else
        {
            st.push(2 * val - mini);
            mini = val;
        }
    }
    void pop()
    {
        if (st.empty())
            return;
        int x = st.top();
        st.pop();
        if (mini > x)
        {
            mini = 2 * mini - x;
        }
    }
    int top()
    {
        if (st.empty())
            return -1;
        if (mini < st.top())
        {
            return st.top();
        }
        return mini;
    }
};
int main()
{
}