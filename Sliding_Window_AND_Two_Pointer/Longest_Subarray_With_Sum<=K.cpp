//Subarray can be replaced with Substring
// some condition is given (let say in this sum <= k)
//Select consecutive "k" elements such that their sum is Maximum
//// k = 14
//m2
#include<bits/stdc++.h>
using namespace std;
 
 int maxLengthSubbarrayBetter(vector<int>&arr,int k)
 {
       ///Time Complexity - O (n + n)
       int n = arr.size();
       int sum =0;
       int l=0,r=0;
       int maxLength = 0;
       while(r<n)
       {
        sum = sum + arr[r];
        if(sum <= k){
            maxLength = max(maxLength,r-l+1);
        }
        r++;
        while(sum > k)
        {
            sum = sum - arr[l];
            l++;
        }
       }
       return maxLength;
       
 }
 int maxLengthSubbarrayOptimal(vector<int>&arr,int k)
 {
  //It will work only if maximum length of subarray is asked 
  ///Time Complexity - O ( n )
  int n = arr.size();
  int l = 0,r=0;
  int sum = 0;
  int maxLen = 0;
  while(r < n)
  {
       sum = sum + arr[r];
        if(sum <= k){
            maxLen = max(maxLen,r-l+1);
        }
        r++;
        if(sum > k)
        {
            sum = sum - arr[l];
            l++;
        }
  }
    return maxLen;
       
 }

  int main()
  {
    vector<int>arr = {2,5,1,7,10};
     int k= 14;

    cout<<maxLengthSubbarrayBetter(arr,k)<<"\n";
    cout<<maxLengthSubbarrayOptimal(arr,k);
  }