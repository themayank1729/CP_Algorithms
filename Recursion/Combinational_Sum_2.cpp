#include <bits/stdc++.h>
using namespace std;

void printCombinationSum(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
    if (target == 0) {
        for (auto it : ds) {
            cout << it << " ";
        }
        cout << endl;

        ans.push_back(ds);
        return; 
    }

    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1]) continue; // Skip duplicates
        if (arr[i] > target) break; // Stop if the current candidate exceeds the target

        ds.push_back(arr[i]);
        printCombinationSum(i + 1, target - arr[i], arr, ans, ds); // Use i + 1 for next index
        ds.pop_back();
    }
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

    vector<vector<int>> ans; 
    vector<int> ds;

    sort(arr.begin(), arr.end()); // Sort to handle duplicates and enable early termination
    printCombinationSum(0, target, arr, ans, ds);

    return 0;
}
