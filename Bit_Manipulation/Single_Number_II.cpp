// Every number will be appearing thrice except for one number, return that number
#include<bits/stdc++.h>
using namespace std;
int singleNumberBrute(vector<int>&nums)
{
  //Time Complexity - o (n + m)
  //Time Complpexity - O ( m )  
  int ans = -1;
  map<int,int>mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    mpp[nums[i]]++;
  }
  for (auto  it: mpp)
  {
      if(it.second == 1) 
      {
        ans = it.first;
        break;
      }
  }
  return ans;
}

int singleNumberBetter(vector<int>&nums)
{
  //Time Complexity - o (n * 32)
  //Time Complpexity - O ( 1 )  
  int n = nums.size();
  int ans = 0;
  for (int bitIndex = 0; bitIndex < 31; ++bitIndex)
  {
     int cnt =0;
     for (int i = 0; i < n ; ++i)
     {
       if(nums[i] & (1<<bitIndex))
       {
        cnt++;
       }
     }
     if(cnt % 3 == 1)
     {
      ans = ans | (1<<bitIndex);
     }
  }
  return ans;
}
int singleNumberOptimal(vector<int>&nums)
{
  //Time Complexity - o (n * log(n))
  //Time Complpexity - O ( 1 )  
  int n = nums.size();
  int ans = -1;
  sort(nums.begin(),nums.end());
  for (int i = 1; i < n; i+=3)
  {
    if(nums[i-1] != nums[i])
    {
      return nums[i-1];
    }
  }
  return nums[n-1];
}

int singleNumberOptimalBest(vector<int>&nums)
{
  //Time Complexity - o ( n )
  //Time Complpexity - O ( 1 )  
  int n = nums.size();
   int ones = 0,twos =0;
   for (int i = 0; i < n; ++i)
   {
      ones = (ones ^ nums[i]) &(~twos);
      twos = (twos ^ nums[i]) &(~ones);
   }
   return ones;
}
int main()
{
  vector<int>arr= {5,5,5,6,4,4,4};
  cout<<singleNumberBrute(arr)<<"\n";
  cout<<singleNumberBetter(arr)<<"\n";
  cout<<singleNumberOptimal(arr)<<"\n";
   cout<<singleNumberOptimalBest(arr)<<"\n";
}