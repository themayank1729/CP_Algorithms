// Every number will be appearing twice except for two distinct numbers return that two numbers
#include<bits/stdc++.h>
using namespace std;
vector<int> singleNumberBrute(vector<int>&nums)
{
  //Time Complexity - o (n + m)
  //Time Complpexity - O ( m )  
  int first =0 ;
  int second = 0;
  map<int,int>mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    mpp[nums[i]]++;
  }
  for (auto  it: mpp)
  {
      if(it.second == 1 && first == 0) 
      {
        first = it.first;
        
      }
      if(it.second == 1 && it.first != first)
        {
          second = it.first;
        }
  }
  return {first,second};
}
vector<int> singleNumberOptimal(vector<int>&nums)
{
  //Time Complexity - o (n + n)
  //Time Complpexity - O ( 1 )  
  int b1 =0 ;
  int b2 = 0;
  int n =nums.size();
  long int xorN = 0;
  for (int i = 0; i < n; ++i)
  {
    xorN= xorN ^ nums[i];
  }
  int rightMost = (xorN & (xorN - 1))^xorN;
  
  //xor can overflow
  for (int i = 0; i < n; ++i)
  {
    if(nums[i]&rightMost)
    {
      b1^=nums[i];
    }
    else
    {
      b2^=nums[i];
    }
  }
  return {b1,b2};
}




int main()
{
  vector<int>arr= {2,4,2,6,3,7,7,3};
  vector<int>ans;

  ans = singleNumberBrute(arr);
  cout<<ans[0]<<"  "<<ans[1]<<"\n";
  ans = singleNumberOptimal(arr);
  cout<<ans[0]<<"  "<<ans[1]<<"\n";
  //cout<<singleNumberBetter(arr)<<"\n";
  //cout<<singleNumberOptimal(arr)<<"\n";
   //cout<<singleNumberOptimalBest(arr)<<"\n";
}