#include<bits/stdc++.h>
using namespace std;
int distinctCharacterBrute(string &s)
{
    //Time complexity - O ( n * n)
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
       int  hash[3] = {0};
        for (int j = i; j < n; j++)
        {
             if (s[j] >= 'a' && s[j] <= 'c') {
                hash[s[j] - 'a'] = 1;
            }
            if(hash[0]  + hash[1] + hash[2] == 3)
            {
                cnt++;
            }
        }
        
    }
    return cnt;
    
}
int distinctCharacterBruteIsOptimised(string &s)
{
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
       int  hash[3] = {0};
        for (int j = i; j < n; j++)
        {
             if (s[j] >= 'a' && s[j] <= 'c') {
                hash[s[j] - 'a'] = 1;
            }
            if(hash[0]  + hash[1] + hash[2] == 3)
            {
                cnt++;
                cnt = cnt + n - (j+1);//or just cnt = cnt + (n-j);
                break;
            }
        }
        
    }
    return cnt;
    
}
int distinctCharacterOptimised(string &s)
{
    //Time Complexity  - O ( n ) 
    int cnt = 0;
    int n = s.size();
    int lastSeen[3] = {-1,-1,-1};
    for (int i = 0; i < n; i++)
    {
       
        
             if (s[i] >= 'a' && s[i] <= 'c') {
                lastSeen[s[i] - 'a'] = i ;
            }
            if(lastSeen[0] != -1 &&   lastSeen[1] != -1  && lastSeen[2] != -1)
            {
                int minIndex = min({lastSeen[0],lastSeen[1],lastSeen[2]});
                cnt = cnt + (1+ minIndex);
            }
        
        
    }
    return cnt;
    
}
 int main()
 {
    string str = "aaabbccd";
    cout<<distinctCharacterBrute(str);
    cout<<"\n";
    cout<<distinctCharacterBruteIsOptimised(str)<<"\n";
    cout<<distinctCharacterOptimised(str);
 }