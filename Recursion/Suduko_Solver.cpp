#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>> &board, int row, int col, char c)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c)
            return false;
    }
    return true;
}
bool helper(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
        return true;
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }
    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }
    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isSafe(board, row, col, digit))
        {
            board[row][col] = digit;
            if (helper(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}
int main()
{
    vector<vector<char>> board;
    solveSudoku(board);
}