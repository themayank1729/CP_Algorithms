#include<bits/stdc++.h>
using namespace std;
void justDoIt()
{
  int n;
  cin>>n;
  int subset_cnt = (1<<n);
  subset_cnt--;
  std::vector<string> v;
 for (int num  = 0; num < subset_cnt ; num++)
 {
  string str = "";
    for (int i = n-1; i >= 0 ; --i)
  {
     int a = ((num>>i)&1);
     char ch = a + '0';
     
     
     if((str.back() == '1' && ch == '1'))
      {
      	str.clear();
       	break;
      	
      }
      else
      {
      	str = str + ch;
      }
     

   }
    if(!str.empty()) {
   v.push_back(str);};
   
 }
 for (int i = 0; i < v.size(); ++i)
 {
 	cout<<v[i]<<"\n";
 }

}

int main()
{
 int t = 1;
 //cin>>t;
 while(t--)
 {
  justDoIt();
 }
 
 

}