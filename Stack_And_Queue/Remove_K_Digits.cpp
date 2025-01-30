#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
  stack<char> st;
  for (int i = 0; i < num.size(); i++)
  {
    while (!st.empty() && k > 0 && (st.top() - '0' > num[i] - '0'))
    {
      st.pop();
      k--;
    }
    st.push(num[i]);
  }
  while (k > 0)
  {
    st.pop();
    k--;
  }
  if (st.empty())
  {
    return "";
  }
  string res = "";
  while (!st.empty())
  {
    /// res = res + st.top();   Memory Limit Exceeded as it creates string on each step
    res.push_back(st.top());

    st.pop();
  }
  while (!res.empty() && res.back() == '0')
  {
    res.pop_back();
  }
  reverse(res.begin(), res.end());
  if (res.empty())
    return "";
  return res;
}
string removeKdigits(string num, int k)
{
  deque<char> deq;
  string ans = "";
  int i = 0;

  while (i < num.length())
  {
    while (!deq.empty() && deq.back() > num[i] && k > 0) // Pop elements from the stack until the current digit is larger than or equal to the top element or until K reaches zero.
    {
      deq.pop_back();
      k--;
    }
    deq.push_back(num[i++]); // Push the element into the stack
  }

  while (!deq.empty() && k > 0) // Pop elements until K becomes 0
    deq.pop_back(), k--;

  while (!deq.empty() && deq.front() == '0') // Removing the leading Zeros
    deq.pop_front();

  while (!deq.empty())
  {
    ans += deq.front();
    deq.pop_front();
  }

  return ans.empty() ? "0" : ans;
}
int main()
{
  cout << removeKdigits("1432219", 3);
}