// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

using namespace std;

#include <vector>

class Solution {
public:
  int minJumps[10000];

  int jump(vector<int> &nums) {
    fill(minJumps, minJumps + nums.size(), -1);
    minJumps[nums.size() - 1] = 0;
    return dfs(nums, 0);
  }

  int dfs(vector<int> &nums, int index) {
    if (minJumps[index] != -1) {
      return minJumps[index];
    }

    int jumps = 100000;
    for (int i = 1; i <= nums[index]; i++) {
      if (index + i < nums.size()) {
        jumps = min(jumps, dfs(nums, index + i) + 1);
      }
    }

    minJumps[index] = jumps;
    return jumps;
  }
};
