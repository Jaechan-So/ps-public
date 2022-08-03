// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> answer;

    for (auto &num : nums) {
      if (nums[abs(num) - 1] < 0) {
        answer.push_back(abs(num));
      }
      nums[abs(num) - 1] *= -1;
    }

    return answer;
  }
};
