// 1306. Jump Game III
// https://leetcode.com/problems/jump-game-iii/

using namespace std;

#include <vector>

#define abs(x) (((x) >= 0) ? (x) : (-(x)))

class Solution {
public:
  bool canReach(vector<int> &arr, int start) { return dfs(arr, start); }

  bool dfs(vector<int> &arr, int index) {
    if (index < 0 || index >= arr.size()) {
      return false;
    }

    if (arr[index] < 0) {
      return false;
    }

    if (arr[index] == 0) {
      return true;
    }

    arr[index] = -arr[index];

    return dfs(arr, index - abs(arr[index])) ||
           dfs(arr, index + abs(arr[index]));
  }
};
