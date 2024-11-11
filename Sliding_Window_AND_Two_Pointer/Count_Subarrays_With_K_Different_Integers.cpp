#include<bits/stdc++.h>
using namespace std;
int countSubarrayasBrute(vector<int>&nums,int k)
{
  //Time Compllexity = O ( n ^ 2)
  //Connnnnsidered hashing O ( n* n * log (n))
  //Space Complexity = ?
    int count = 0;
    int n = nums.size();
  for (int  i = 0; i < n; i++)
  {
    set<int>st;
    for (int j = i; j < n; j++)
    {
         st.insert(nums[j]);
         if(st.size() == k) count++;
         else if(st.size() > k) break;
    }
     st.clear();
  }
  return count;
  
}
int countSubarrayasOptimal(vector<int>&nums,int k)
{
  //Time Compllexity = O ( n * 2)
  // if Considered hashing O ( 2 * n * log (n))
  //Space Complexity = O ( n )
    int count = 0;
    int n = nums.size();
  int r = 0,l=0;
  map<int,int>mpp;

  while(r<n)
  {
    mpp[nums[r]]++ ;
    while(mpp.size() > k)
    {
       mpp[nums[l]]--;
       if(mpp[nums[l]] == 0)
       {
        mpp.erase(nums[l]);
       }
       l++;
    } 
    count = count + (r - l + 1);
    r++; 
  }

  return count;
  
}
int main()
{
    vector<int>nums = {1,2,1,3,4};
    int k =  3;
    cout<<countSubarrayasBrute(nums,k)<<"\n";
    cout<<(countSubarrayasOptimal(nums,k)-countSubarrayasOptimal(nums,k-1));
    
}