#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
bool isSafe(int row,int col,vector<string>&board,int n)
{
   //check for upper diagonal
   int duprow = row;
   int dupcol = col;
   while(row>=0 && col>=0)
   {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
   }
   row = duprow;
   col = dupcol;
   //for horizontal left
   while(col>=0)
   {
    if(board[row][col] == 'Q') return false;
     col--;
   }
   row= duprow;
   col =dupcol;
   while(row < n && col>=0)
   {
      if(board[row][col] == 'Q')
      return false;
      row++;
      col--;
   }
   return true;

}

void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
{
 if(col == n) {
    cnt++;
    ans.push_back(board);
     
    return;
 }
 for (int row = 0; row < n; row++)
 {
     if(isSafe(row,col,board,n))
     {
        board[row][col] = 'Q';
        solve(col+1,board,ans,n);
        board[row][col] = '.';
     }
 }
 
}
void solveNqueens(int n)
{
     vector<string>board(n);
    string s(n,'.');
    for (int i = 0; i < n; ++i)
    {
        board[i] = s;
    }
     vector<vector<string>>ans;
     solve(0,board,ans,n);
     cout<<cnt<<" \n";
     for ( auto it : ans)
     {
       for ( auto i : it)
        {
        cout<<i<<"\n";
       }
     cout<<"\n\n";
     }
     
}
int main()
{
     solveNqueens(4);
}