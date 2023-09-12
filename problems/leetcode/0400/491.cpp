// 491. Non-decreasing Subsequences
// https://leetcode.com/problems/non-decreasing-subsequences/description/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  vector<vector<int>> answer;
  vector<int> sequence;
  set<vector<int>> appeared;

  void track(vector<int> &nums, int index) {
    if (index == nums.size()) {
      if (sequence.size() >= 2 && appeared.find(sequence) == appeared.end()) {
        appeared.insert(sequence);
        answer.push_back(sequence);
      }
      return;
    }

    if (sequence.empty() || sequence.back() <= nums[index]) {
      sequence.push_back(nums[index]);
      track(nums, index + 1);
      sequence.pop_back();
    }

    track(nums, index + 1);
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    track(nums, 0);
    return answer;
  }
};
