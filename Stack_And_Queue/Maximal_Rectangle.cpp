#include <bits/stdc++.h>
using namespace std;
int maxRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    int element = -1;
    int NSE, PSE;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            element = st.top();
            st.pop();
            NSE = i;
            PSE = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
        }
        st.push(i);
    }
    while (!st.empty())
    {
        NSE = n;
        element = st.top();
        st.pop();
        PSE = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, heights[element] * (NSE - PSE - 1));
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
          int rows = matrix.size();
          int cols = matrix[0].size();
          int count = 0;
          //cout<<rows<<" "<<cols<<" \n";

          vector<vector<int>>preSum(rows,vector<int>(cols,0));
          
          
          for (int i = 0; i < cols; i++)
          {
            count = 0;
            for (int j = 0; j < rows; j++)
            {
                   if(matrix[j][i] == '1')
                   count++;
                   else
                   count = 0;
                   preSum[j][i] = count;

            }  
          }
          /*For debugging purpose
          for (int i = 0; i < rows; i++)
          {
            for (int j = 0; j < cols; j++)
            {
                cout<<preSum[i][j]<<" ";
            }
            cout<<"\n";
            
          }
          */
          int maxArea = 0;
          for (int i = 0; i < rows; i++)
          {
            maxArea = max(maxArea,maxRectangleArea(preSum[i]));
          }
          
          
          return maxArea;
        
}
int main()
{
    vector<vector<char>> matrix2 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
      cout << maximalRectangle(matrix);
   
}