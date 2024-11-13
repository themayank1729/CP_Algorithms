#include<bits/stdc++.h>
using namespace std;
int divide(int dividend,int divisor)
{
  //Time complexity - log(dividend/divisor) 
    if(dividend == divisor) return 1;
    bool sign = true;
    if(dividend >=0 && divisor<0) sign = false;
    if(dividend <0 && divisor>=0) sign = false;
    long n = abs(dividend);
    long d = abs(divisor);
    divisor = abs(divisor);
    long quotient = 0;
    while(n>=d)
    {
      int cnt = 0;
      while(n >= (d<<(cnt+1)))
       {
        cnt+=1;
       }
       quotient = quotient + (1<<cnt);
       n = n - (d<<cnt);
    }
    if(quotient == (1<<31) && sign)
    {
      return INT_MAX;
    }
    if(quotient == (1<<31) && !sign)
    {
      return INT_MIN;
    }
    return sign ? quotient : -quotient;
}
int main()
{
     int l,r;
     cin>>l>>r;
     cout<<divide(l,r);
   }