// 873. Length of Longest Fibonacci Subsequence
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/

using namespace std;

#include <vector>

class Solution {
public:
  int getLen(vector<int> &arr, int i, int j, vector<vector<int>> &lens) {
    if (lens[i][j] != -1) {
      return lens[i][j];
    }

    vector<int>::iterator iter =
        lower_bound(arr.begin() + j + 1, arr.end(), arr[i] + arr[j]);
    if (iter == arr.end() || *iter != arr[i] + arr[j]) {
      lens[i][j] = 0;
    } else {
      lens[i][j] = 1 + getLen(arr, j, iter - arr.begin(), lens);
    }

    return lens[i][j];
  }

  int lenLongestFibSubseq(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> lens(n, vector<int>(n, -1));

    int longest = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        longest = max(longest, getLen(arr, i, j, lens));
      }
    }

    return longest == 0 ? 0 : 2 + longest;
  }
};
