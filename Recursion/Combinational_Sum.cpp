#include <bits/stdc++.h>
using namespace std;

void printCombinationSum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    if (target == 0) {
        for (auto it : ds) {
            cout << it << " ";
        }
        cout << endl;

        ans.push_back(ds);
        return; // Exit early after finding a valid combination
    }

    if (ind == arr.size()) {
        return;
    }

    // Picking up the element
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        printCombinationSum(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    // Skipping the element
    printCombinationSum(ind + 1, target, arr, ans, ds);
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr; // Input array
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<vector<int>> ans; // To store all valid combinations
    vector<int> ds; // To store the current combination

    printCombinationSum(0, target, arr, ans, ds);

    return 0;
}
