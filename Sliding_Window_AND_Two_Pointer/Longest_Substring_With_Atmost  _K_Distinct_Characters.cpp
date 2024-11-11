#include<bits/stdc++.h>
using namespace std;
int maxSubstringBetter(string &s,int k)
{
    //Time Complexity - O ( 2 * n)
  int maxLen =0;
  map<int,int>mpp;
  int l =0,r=0;
  int n = s.size();
  while (r<n)
  {
    mpp[s[r]]++;
    if(mpp.size()<=k)
    {
        maxLen = max(maxLen,r-l+1);
    }
     if(mpp.size() > k)
    {
             while(mpp.size()  > k )
            {
                mpp[s[l]]--;
               if(mpp[s[l]] == 0) 
               {
                       if (mpp.find(s[l]) != mpp.end()) {
                           mpp.erase(s[l]); 
                          }
               }
               l++;
            }
   }
    r++;
  }
  return maxLen;
}
int maxSubstringOptimal(string &s,int k)
{
    //Time Complexity - O ( n)
  int maxLen =0;
  map<int,int>mpp;
  int l =0,r=0;
  int n = s.size();
  while (r<n)
  {
    mpp[s[r]]++;
    if(mpp.size()<=k)
    {
        maxLen = max(maxLen,r-l+1);
    }
     if(mpp.size() > k)
    {
         mpp[s[l]]--;
         if(mpp[s[l]] == 0) mpp.erase(s[l]);       
               l++;
     }
    r++;
  }
  return maxLen;
}
int main()
{
string s = "aaabbccddd";
int k =2;
//cout<<maxSubstring(s,k);
cout<<maxSubstringBetter(s,k);
cout<<maxSubstringOptimal(s,k);
}