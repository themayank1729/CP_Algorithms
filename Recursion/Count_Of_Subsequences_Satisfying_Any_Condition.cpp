#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define nline "\n"
//there is no need to store the subsequences since the sum is only required
//let say the condition is that sum of subsequence should be Sum that is given
int countOfSubsequences(int i,int n,int toBeSum,int sum,vector<int>&arr,vector<int>&ans)
{
   if(toBeSum > sum) return 0;
   if(i == n)
   {
     if(toBeSum == sum )
     {
       return 1;
     }
     return 0;
   }
   ans.pb(arr[i]);
   toBeSum = toBeSum + arr[i];
   int l = countOfSubsequences(i+1,n,toBeSum,sum,arr,ans);
   ans.ppb();
   toBeSum = toBeSum - arr[i];
   int r = countOfSubsequences(i+1,n,toBeSum,sum,arr,ans);
  return l+r;
}
int main()
{
    //Let say the condition given is to make subsequence whose sum is k
    int n,sum;
    cin>>n>>sum;
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        arr.pb(num);
    }
    vector<int>ans;
    cout<<"Count of subsequences satisfying condition is : "<<countOfSubsequences(0,n,0,sum,arr,ans);
}


