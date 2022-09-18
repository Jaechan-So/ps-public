// 78. Subsets
// https://leetcode.com/problems/subsets/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> powerSet;
  int len;

  void dfs(vector<int> &nums, vector<int> &currentNums, int next) {
    if (len <= next) {
      return;
    }

    currentNums.push_back(nums[next]);

    vector<int> currentSet(currentNums);
    powerSet.push_back(currentSet);

    for (int i = next + 1; i < len; i++) {
      dfs(nums, currentNums, i);
    }

    currentNums.pop_back();
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    len = nums.size();
    vector<int> currentNums;

    vector<int> emptySet;
    powerSet.push_back(emptySet);

    for (int i = 0; i < len; i++) {
      dfs(nums, currentNums, i);
    }

    return powerSet;
  }
};
