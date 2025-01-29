#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string &str)
{
   stack<char> st;
   for (int i = 0; i < str.size(); i++)
   {
      if (str[i] == '(' || str[i] == '{' || str[i] == '[')
      {
         st.push(str[i]);
      }
      else
      {
         if (st.empty())
            return false;
         char ch = st.top();

         if ((str[i] == ')' && ch == '(') || (str[i] == '}' && ch == '{') || (str[i] == ']' && ch == '['))
         {
            st.pop();
         }
         else
            return false;
      }
   }
   return st.empty();
}
int main()
{
   string str;
   cin >> str;
   if (isBalanced(str))
   {
      cout << "String is  Balanced\n";
   }
   else
   {
      cout << "string is Unbalanced\n";
   }
}