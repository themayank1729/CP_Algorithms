#include <bits/stdc++.h>
using namespace std;
/*
 -------------------------------------Better Approach ---------------------------------------------------
 Class Based leetcode solution class StockSpanner {
public:
vector<int>arr;
    StockSpanner() {
        arr = {};
    }

    int next(int price) {
        arr.push_back(price);
        int count = 1;
        for(int i = arr.size() - 2; i >= 0; i--)
        {
            if(arr[i] <= price)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};
s
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*
---------------------------------------------------Optimal Approach----------------------------------------
class StockSpanner {
public:
stack<pair<int,int>>st;
    int index = -1;
    StockSpanner() {
        index = -1;
        st = stack<pair<int,int>>();
    }

    int next(int price) {
       index = index  + 1;
       while(!st.empty() && st.top().first <= price )
       {
        st.pop();
       }
      int ans = index - (st.empty()? -1 :  st.top().second);
      st.push({price,index});
      return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

vector<int> next(vector<int> &arr)
{

    int n = arr.size();
    int count = 1;
    vector<int> ans;
    vector<int> days;
    for (int i = 0; i < arr.size(); i++)
    {
        count = 1;
        if (!ans.empty() && (ans.back() <= arr[i]))
        {
            int j = i - 1;
            while (j >= 0 && ans[j] <= arr[i])
            {
                count++;
                j--;
            }
        }
        days.push_back(count);
        ans.push_back(arr[i]);
    }
    return days;
}
int main()
{
    vector<int> arr = {7, 2, 1, 3, 3, 1, 8};
    vector<int> ans = next(arr);
    for (auto itv : ans)
    {
        cout << itv << " ";
    }
}