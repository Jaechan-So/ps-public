// 487. Max Consecutive Ones II
// https://leetcode.com/problems/max-consecutive-ones-ii/description/

using namespace std;

#include <vector>

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    vector<int> v;
    for (int num : nums) {
      if (num == 0) {
        v.push_back(0);
      } else {
        if (v.empty() || v.back() == 0) {
          v.push_back(1);
        } else {
          v[v.size() - 1]++;
        }
      }
    }

    int maxLen = 1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0) {
        continue;
      }

      int localMaxLen = v[i];
      if (i - 2 >= 0 && v[i - 2] != 0) {
        localMaxLen = max(localMaxLen, v[i - 2] + 1 + v[i]);
      } else if (i - 1 >= 0) {
        localMaxLen = max(localMaxLen, 1 + v[i]);
      }
      if (i + 2 < v.size() && v[i + 2] != 0) {
        localMaxLen = max(localMaxLen, v[i] + 1 + v[i + 2]);
      } else if (i + 1 < v.size()) {
        localMaxLen = max(localMaxLen, v[i] + 1);
      }

      maxLen = max(maxLen, localMaxLen);
    }

    return maxLen;
  }
};
