// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int answer = 0;

    unordered_map<int, pair<int, int>> numAndPrevAndNext;

    for (auto &num : nums) {
      if (numAndPrevAndNext.find(num) != numAndPrevAndNext.end()) {
        continue;
      }

      numAndPrevAndNext[num] = {num, num};

      if (numAndPrevAndNext.find(num - 1) != numAndPrevAndNext.end()) {
        numAndPrevAndNext[num - 1].second = num;
        numAndPrevAndNext[num].first = num - 1;
      }

      if (numAndPrevAndNext.find(num + 1) != numAndPrevAndNext.end()) {
        numAndPrevAndNext[num + 1].first = num;
        numAndPrevAndNext[num].second = num + 1;
      }
    }

    for (auto &p : numAndPrevAndNext) {
      answer = max(answer, getConnectedLength(numAndPrevAndNext, p.first));
    }

    return answer;
  }

  int getConnectedLength(unordered_map<int, pair<int, int>> &numAndPrevAndNext,
                         int num) {
    int prev = numAndPrevAndNext[num].first,
        next = numAndPrevAndNext[num].second;

    if (prev == num - 2 && next == num + 2) {
      return 0;
    }

    numAndPrevAndNext[num].first = num - 2;
    numAndPrevAndNext[num].second = num + 2;

    return 1 + (prev == num ? 0 : getConnectedLength(numAndPrevAndNext, prev)) +
           (next == num ? 0 : getConnectedLength(numAndPrevAndNext, next));
  }
};
