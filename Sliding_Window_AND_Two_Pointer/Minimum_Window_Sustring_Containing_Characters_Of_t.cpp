//Minimum length substring that has all characters of string  varaible test
#include<bits/stdc++.h>
using namespace std;
string minimumWindowSubstring_Optimised_Brute(string &str,string t)
{
    int minLen = INT_MAX;
    int cnt = 0;
    int n =str.size();
    int m = t.size();
    int startIndex = -1;
  for (int i = 0; i < n; i++)
  {
    int hash[256] = {0};
    for (int j = 0; j < m; i++)
    {
        hash[t[j]]++;
    }
    for (int j = 0; j < n; j++)
    {
        if(hash[str[j]] > 0)
        {
          hash[str[j]]--;
        }
        if(j - i + 1  < minLen )
        {
            minLen = j - i + 1;
            startIndex = i;
            break;

        } 
    }
    
    
  }
  return str.substr(startIndex,minLen);
  
} 
int main()
{
   string str = "ddaaabbcc";
   string t = "abc";
   cout<<minimumWindowSubstring_Optimised_Brute(str,t);
} 