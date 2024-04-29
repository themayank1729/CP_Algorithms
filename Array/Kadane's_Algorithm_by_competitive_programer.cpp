// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         int n=nums.size();
//         int sum=0;
//         int maxi=INT_MIN;
//         int maxi1=INT_MIN;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             if(sum<0){
//                 maxi1=max(sum,maxi1);
//                 sum=0;
//             }
//             else if(sum>maxi) maxi=sum;
//         }
//         if(maxi>=0) return maxi;
//         return maxi1;

//         //Brute Force TC: n^2   SC: 1
//         // int maxi=INT_MIN;
//         // int n=nums.size();
//         // for(int i=0;i<n;i++){
//         //     int sum=0;
//         //     for(int j=i;j<n;j++){
//         //         sum+=nums[j];
//         //         if(sum>maxi) maxi=sum;
//         //     }
//         // }
//         // return maxi;
//     }
// };
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int speedUp = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

// Function to extract digit value from a character
int digit(char c)
{
    return c & 15;
}

// Function to check if a character is a digit
bool isDigit(char c)
{
    return '0' <= c && c <= '9';
}

int in = []
{
    std::ofstream out("user.out"); // Redirect cout to user.out
    std::cout.rdbuf(out.rdbuf());

    int ans, sum;
    bool _neg;

    // Read input line by line
    for (std::string s; std::getline(std::cin, s); std::cout << '\n')
    {
        ans = -1e9, sum = 0; // Initialize answer and sum for each input line

        for (int _i = 1, _n = s.length(), v; _i < _n; ++_i)
        {
            _neg = false; // Initialize flag to indicate negative number

            if (s[_i] == '-')
            {                // Check for negative sign
                ++_i;        // Move to next character after '-'
                _neg = true; // Set flag to true for negative number
            }

            v = digit(s[_i]); // Extract first digit

            // Extract remaining digits to form the number
            while (isDigit(s[++_i]))
                v = v * 10 + digit(s[_i]);

            // Negate the value if it was negative
            if (_neg)
                v = -v;

            // Do stuff with v (not specified in the provided code)

            // Update answer by taking maximum of current answer and sum
            ans = std::max(ans, sum < 0 ? sum = v : sum += v);
        }

        // Output the answer
        std::cout << ans;
    }

    // Exit after processing input
    exit(0);
    return 0;
}();

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        return 0; // Placeholder, not implemented
    }
};