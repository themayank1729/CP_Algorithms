  #include<bits/stdc++.h>
  using namespace std;
  void getAns(vector<vector<int>>& mat, int row, int col, vector<string>& ans, string& path) {
    int n = mat.size();

    // Base Case: Reached the destination
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    mat[row][col] = 0;

    // UP call
    if (row - 1 >= 0 && mat[row - 1][col] == 1) {
        path.push_back('U');
        getAns(mat, row - 1, col, ans, path);
        path.pop_back();
    }

    // DOWN call
    if (row + 1 < n && mat[row + 1][col] == 1) {
        path.push_back('D');
        getAns(mat, row + 1, col, ans, path);
        path.pop_back();
    }

    // LEFT call
    if (col - 1 >= 0 && mat[row][col - 1] == 1) {
        path.push_back('L');
        getAns(mat, row, col - 1, ans, path);
        path.pop_back();
    }

    // RIGHT call
    if (col + 1 < n && mat[row][col + 1] == 1) {
        path.push_back('R');
        getAns(mat, row, col + 1, ans, path);
        path.pop_back();
    }

    // Unmark the current cell (Backtrack)
    mat[row][col] = 1;
}
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans = {};
        string path;
        if(mat[0][0] == 0) return ans;
        if(mat[mat.size() - 1][mat.size()-1] == 0) return ans;
        getAns(mat,0,0,ans,path);
        return ans;
    }
    //****************************************************************************************************************** */ Second variation (no need of popping back )

   void helper(vector<vector<int>> &mat,int r,int c,string path,vector<string>&ans)
         {
            int n =mat.size();
            if(r<0 || c<0 || r>=n || c >= n || mat[r][c] == 0)
            {
                return;
            }
            if(r == n-1 && c == n-1) {
                ans.push_back(path);
                return;
            }
            mat[r][c] = 0; //marking zero
            helper(mat,r+1,c,path+"D",ans);
            helper(mat,r-1,c,path+"U",ans); //creates a new memory space for each  time for string path
            helper(mat,r,c-1,path+"L",ans);
            helper(mat,r,c+1,path+"R",ans);
            mat[r][c] = 1;
         }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        string path;
        helper(mat,0,0,path,ans);
        return ans;
    }
  //************************************************************************************************************ */
    int main()
    {
        
    }