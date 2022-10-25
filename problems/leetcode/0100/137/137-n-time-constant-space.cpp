// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

using namespace std;

#include <vector>

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int once = 0, twice = 0;

    for (auto num : nums) {
      once = ~twice & (once ^ num);
      twice = ~once & (twice ^ num);
    }

    return once;
  }
};
