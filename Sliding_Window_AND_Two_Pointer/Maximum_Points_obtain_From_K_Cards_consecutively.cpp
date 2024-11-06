//condition - Select cards either from left or right or from both edges of the arary
#include<bits/stdc++.h>
using namespace std;
 
 int maxPointsOptimal(vector<int>&arr,int k)
 {
       ///Time Complexity - O (k + k)
       //SC - O(1)
       int n = arr.size();
       int left_sum = 0;
       for (int i = 0; i < k; i++)
       {
         left_sum = left_sum + arr[i]; 
       }
       int maxSum = left_sum;
       int right_Sum  = 0;
       int right_index = n-1;
       for(int i = k-1; i >=0 ; i--)
       {
          left_sum = left_sum - arr[i];
          right_Sum = right_Sum + arr[right_index];
           right_index--;
           maxSum = max(maxSum,left_sum + right_Sum);
       }
       return maxSum;
        
       
       
 }
 
  int main()
  {
    vector<int>arr = {6,2,3,4,7,2,1,7,1};
     int k= 4;

    cout<<maxPointsOptimal(arr,k)<<"\n";
 //   cout<<maxLengthSubbarrayOptimal(arr,k);
  }