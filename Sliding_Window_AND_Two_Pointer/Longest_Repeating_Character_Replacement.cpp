// String is given only in upper case;
// maximum k elements can be replaced  such that you have to get the maximum
// length of substring possible
#include <bits/stdc++.h>
using namespace std;
int longestRepeatingcharactersBrute(string &s, int k) {
  // Time Complexity - O ( n ^ 2)
  int maxLen = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    int hash[26] = {0};
    int maxFre = 0;
    for (int j = i; j < n; j++) {
      if (s[j] >= 'A' && s[j] <= 'Z') {
        hash[s[j] - 'A']++;
      }

      maxFre = max(maxFre, hash[s[j] - 'A']);
      int changes = (j - i + 1) - maxFre;
      if (changes <= k) {
        maxLen = max(maxLen, j - i + 1);
      } else
        break;
    }
  }
  return maxLen;
}
int longestRepeatingcharactersBetter(string &s, int k) {
  // Time Complexity - O ( n + n ) * O ( 26 )
  int maxLen = 0;
  int l = 0, r = 0;
  int hash[26] = {0}; // for storing the frequecy of each element
  int n = s.size();
  int maxFre = 0;
  while (r < n) {
    hash[s[r] - 'A']++;
    maxFre = max(maxFre, hash[s[r] - 'A']);
    while ((r - l + 1) - maxFre > k) {
      hash[s[l] - 'A']--;
      maxFre = 0;
      for (int i = 0; i < 26; ++i) {
        maxFre = max(maxFre, hash[i]);
      }
      l++;
    }
    if ((r - l + 1) - maxFre <= k) {
      maxLen = max(maxLen, r - l + 1);
    }
    r++;
  }
  return maxLen;
}
int longestRepeatingcharactersOptimal(string &s, int k) {
  // Time Complexity - O ( n )
  int maxLen = 0;
  int l = 0, r = 0;
  int hash[26] = {0}; // for storing the frequecy of each element
  int n = s.size();
  int maxFre = 0;
  while (r < n) {
    hash[s[r] - 'A']++;
    maxFre = max(maxFre, hash[s[r] - 'A']);
    if ((r - l + 1) - maxFre > k) {
      hash[s[l] - 'A']--;
      l++;
    }
    if ((r - l + 1) - maxFre <= k) {
      maxLen = max(maxLen, r - l + 1);
    }
    r++;
  }
  return maxLen;
}
int main() {
  string str = "AABABBA";
  int k = 2; // given by user;
  cout << longestRepeatingcharactersBrute(str, k);
  cout << longestRepeatingcharactersBetter(str, k);
  cout << longestRepeatingcharactersOptimal(str, k);
}
