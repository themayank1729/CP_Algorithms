#include<bits/stdc++.h>
using namespace std;
int maxLengthSubstringBrute(string &str)
{
 //Genenrating all substrings 
 //Time Complexity - O ( n * n)
 int n = str.length();
 int maxLen = 0;
 for (int i = 0; i < n; i++)
 {
    int hash[256] = {0};
    for (int j = i; j < n; j++)
    {
        if(hash[str[j]] == 1) break;
        int len = j - i + 1;

        maxLen = max(maxLen,len);
        hash[str[j]]=1;

        
    }
    
 }
 return maxLen;
}
int maxLengthSubstringOptimal(string &str)
{ 
 //Time Complexity - O ( n )
 int n = str.length();
 int maxLen = 0;
 int hash[256] = {-1};
 int l =0;
 int r=0;
  while(r< n)
  {
    if(hash[str[r]] != -1 )
    {
        if(hash[str[r]] >= l)
        {
            l = hash[str[r]]+1;
        }            
    }
    int len = r-l+1;
    maxLen = max(len,maxLen);
    hash[str[r]] = r;
    r++;
  }
 return maxLen;
}

int main()
{
    string str;
    getline(cin,str);
    cout<<maxLengthSubstringBrute(str); 
     cout<<maxLengthSubstringOptimal(str); 
}