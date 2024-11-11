#include<bits/stdc++.h>
using namespace std;
int sumGreaterThanOrEqualToK(vector<int>nums,int k)
{
  if(k < 0)  return 0;
  int n = nums.size();
  int l=0,r=0,sum=0,cnt=0;
  while(r<n)
  {
            sum+=nums[r];
            while(sum > k)///through out whole function it takes n times to execute
            {
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
  }   
  return cnt;
}

int main()
{
  //Time Complexity - O ( 2 * ( 2 * n));
    vector<int>nums =  {1,0,1,0,1};
    int k = 2; // goal = 2;
    cout<<(sumGreaterThanOrEqualToK(nums,k) - sumGreaterThanOrEqualToKhe(nums,k-1));
}