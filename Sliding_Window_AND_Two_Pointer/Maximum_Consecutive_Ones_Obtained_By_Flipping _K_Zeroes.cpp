//Longest subaarray with atmost k zeroes not beyond it 
#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnesBrute(vector<int>&arr,int k)
{
    //Time Complexity - O ( n ^ 2)
        ///Brute force approach
    //reserve  k zeroes for each subarray and increase zeroes ++ , and if zeroes exceeded k then break
 int n = arr.size();
 int zeroes = 0;
 int maxLen =0;
 for (int i = 0; i < n; i++)
 {
    zeroes = 0;
    for (int j = i; j < n; j++)
    {
        if(arr[j] == 0) zeroes++;
        if(zeroes <= k){
            maxLen = max(maxLen,j-i+1 );
        }
        else
        {
            break;
        }

    }
   
 }
  return maxLen;
}
int maxConsecutiveOnesBetter(vector<int>&arr,int k)
{
    //Time Complexity - O ( n + n)
        ///Better force approach
    //whenever reserve  zeroes  finishes for each subarray and  then we will shrink the window such that in window there can be maximum of k zeroes
     int n = arr.size();
 int zeroes = 0;
 int maxLen =0;
 int l=0,r=0;
 while(r<n)
 {
     if(arr[r] == 0) zeroes++;
     while(zeroes > k)
     {
        if(arr[l] == 0) zeroes--;
        l++;
     }
     if(zeroes <= k)
     {
        maxLen = max(maxLen,r-l+1);
     }
     r++;
 }
 
    return maxLen;
 }
 int maxConsecutiveOnesOptimal(vector<int>&arr,int k)
{
    //Time Complexity - O ( n )
        ///Optimal Best force approach
    //whenever reserve  zeroes  finishes for each subarray and  then we will maintian  that widow size by  moving both (l,r) i.e., the whole winndow moves  and decrease the value of zeroes that is reached to maximum of limit that is k, annd note we will count the length onnly if  zeroes <= k
     int n = arr.size();
 int zeroes = 0;
 int maxLen =0;
 int l=0,r=0;
 while(r<n)
 {
     if(arr[r] == 0) zeroes++;
     if(zeroes > k)
     {
        if(arr[l] == 0) zeroes--;
        l++;
     }
     if(zeroes <= k)
     {
        maxLen = max(maxLen,r-l+1);
     }
     r++;
 }
 
    return maxLen;
 }


int main()
{
   vector<int>arr = {1,1,1,0,0,0,1,1,1,1,0}; // output - 6
   int k = 2;
   cout<<maxConsecutiveOnesBrute(arr,k)<<" \n";
   cout<<maxConsecutiveOnesBetter(arr,k)<<" \n";
   cout<<maxConsecutiveOnesOptimal(arr,k)<<"\n";
}
