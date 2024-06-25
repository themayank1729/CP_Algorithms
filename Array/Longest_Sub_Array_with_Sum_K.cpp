#include<bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
      int len =0;
      int max_len=0;
      unordered_map<int,int> presumMap;
      long long sum =0 ;
      for(int i=0;i<N;i++)
      {
          sum += A[i];
          if(sum== K)
          {
              max_len = max(max_len,i+1);
          }
          long long rem = sum -K;
          if(presumMap.find(rem) != presumMap.end())
          {
              int len = i - presumMap[rem];
              max_len = max(max_len,len);
          }
          if(presumMap.find(sum) == presumMap.end())
          {
              presumMap[sum] = i;
          }
      }
      return max_len;
    } 
    int main()
    {
        
    }
