// 55. Jump Game
// https://leetcode.com/problems/jump-game/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int len = nums.size();
    vector<int> possible(len, 0);

    queue<int> q;
    q.push(len - 1);
    possible[len - 1] = 1;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int i = cur - 1; i >= 0; i--) {
        if (possible[i] == 0 && i + nums[i] >= cur) {
          if (i == 0) {
            return true;
          }
          q.push(i);
          possible[i] = 1;
        }
      }
    }

    return possible[0] == 1;
  }
};
