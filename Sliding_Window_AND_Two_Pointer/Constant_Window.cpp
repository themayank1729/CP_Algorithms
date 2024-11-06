//Select consecutive "k" elements such that their sum is Maximum
//m1
#include<bits/stdc++.h>
using namespace std;
 
 int maxSumOfConstantLength(vector<int>&arr,int k)
 {
       int sum =0;
       for ( int i = 0; i < k; i++)
       {
        sum+=arr[i];
       }
       int l=0;
       int r = k-1;
       int maxSum = INT_MIN;;
       while(r < arr.size()-1)
       {
         sum = sum - arr[l];
         l++;
         r++;
         sum += arr[r];
         maxSum = max(sum,maxSum);
       }
       return maxSum;
       
 }

  int main()
  {
    vector<int>arr = {-1,2,3,3,4,5,-1};
     int k= 4;

    cout<<maxSumOfConstantLength(arr,k);
  }