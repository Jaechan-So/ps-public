// 1027. Longest Arithmetic Subsequence
// https://leetcode.com/problems/longest-arithmetic-subsequence/description/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestArithSeqLength(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, unordered_map<int, int>> memo;

    int maxLen = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int s = nums[i] - nums[j];

        if (memo.find(j) != memo.end() && memo[j].find(s) != memo[j].end()) {
          memo[i][s] = memo[j][s] + 1;
        } else {
          memo[i][s] = 2;
        }

        maxLen = max(maxLen, memo[i][s]);
      }
    }

    return maxLen;
  }
};

// dp(i, s): nums[i]로 끝나는 계차 s인 수열의 최대 길이
// k = 0 to (i - 1): s = nums[i] - nums[k], dp(i, s) = dp(k, s) + 1
