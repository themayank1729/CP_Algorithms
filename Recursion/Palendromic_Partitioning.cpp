#include <bits/stdc++.h>
using namespace std;
// below is Apna college****************************************************************************************************************************************
bool isPalendrome(string &str)
{
    int i = 0;
    int j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
    // string s2 = str;
    // reverse(s2.begin(),s2.end());
    // return s2 == str;
}
void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(partitions);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i + 1);
        if (isPalendrome(part))
        {
            partitions.push_back(part);
            getAllParts(s.substr(i + 1), partitions, ans);
            partitions.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> partitions;
    vector<vector<string>> ans;
    getAllParts(s, partitions, ans);
    return ans;
}
// Below is Striver DSA*****************************************************************************************************************************
bool isPalendrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}
void getAllParts(int index, string s, vector<string> &partitions, vector<vector<string>> &ans)
{
    if (s.size() == index)
    {
        ans.push_back(partitions);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        string part = s.substr(index, i - index + 1);
        if (isPalendrome(s, index, i))
        {
            partitions.push_back(part);
            getAllParts(i + 1, s, partitions, ans);
            partitions.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> partitions;
    vector<vector<string>> ans;
    getAllParts(0, s, partitions, ans);
    return ans;
}
int main()
{
    vector<vector<string>> res = partition("aab");
}