#include <bits/stdc++.h>
using namespace std;

void justDoIt()
{
   string a;
   getline(cin,a);
   int n= a.size();
   int i=0,j=0;
   for (int k = 0; k < n; ++k)
   {
       if(a[k] != ' ') {
        i=k;
        break;
        
       }
   }
   j = i;
   string b;
   //cout<<i<<" "<<j;
   while(j<n)
   {
    if(a[j] == ' ' || j == n-1) 
    {
      if( j != n-1)

       b = a.substr(i,j-i);
      else 
       b = a.substr(i,j-i+1);
      
      reverse(b.begin(),b.end());
      cout<<b<<" ";
      i=j+1;
    }
     j++;
   }

}
void solution() {
  //Optimised solution
    	string s;
    int flag = 0;
    while (cin >> s) {
        reverse(s.begin(), s.end());
        if (flag) {
            cout << " ";
        }
        flag = 1;
        cout << s;
    }
}


int main()
{
    int t = 1;
    //cin >> t;
    while (t--)
    {
        justDoIt();
    }
}

