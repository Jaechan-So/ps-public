// 15. 3Sum
// https://leetcode.com/problems/3sum/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
      if (isPivotableIndex(nums, i)) {
        set<int> seenNums;

        for (int j = i + 1; j < nums.size(); j++) {
          int remain = -nums[i] - nums[j];
          if (seenNums.count(remain)) {
            answer.push_back(vector<int>({nums[i], nums[j], remain}));
            while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
              j++;
            }
          }

          seenNums.insert(nums[j]);
        }
      }
    }

    return answer;
  }

  bool isPivotableIndex(vector<int> &nums, int index) {
    return index == 0 || nums[index - 1] != nums[index];
  }
};
