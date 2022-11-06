// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> answer({-1, -1});

    vector<int>::iterator startIter =
        lower_bound(nums.begin(), nums.end(), target);
    if (startIter == nums.end() || *startIter != target) {
      return answer;
    }

    answer[0] = startIter - nums.begin();

    vector<int>::iterator endIter =
        lower_bound(nums.begin(), nums.end(), target + 1);
    answer[1] = endIter - nums.begin() - 1;

    return answer;
  }
};
