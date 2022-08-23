// 2161. Partition Array According to Given Pivot
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> answer;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < pivot) {
        answer.push_back(nums[i]);
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == pivot) {
        answer.push_back(nums[i]);
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > pivot) {
        answer.push_back(nums[i]);
      }
    }

    return answer;
  }
};
