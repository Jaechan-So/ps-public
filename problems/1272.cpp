// 1272. Remove Interval
// https://leetcode.com/problems/remove-interval/

#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> answer;

 public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                     vector<int>& toBeRemoved) {
    int toBeRemovedStart = toBeRemoved[0];
    int toBeRemovedEnd = toBeRemoved[1];

    for (auto interval : intervals) {
      int start = interval[0];
      int end = interval[1];
      vector<int> removedInterval;

      if (toBeRemovedStart <= start) {
        if (toBeRemovedEnd <= start) {
          answer.push_back(vector<int>({start, end}));
        } else if (start < toBeRemovedEnd && toBeRemovedEnd < end) {
          answer.push_back(vector<int>({toBeRemovedEnd, end}));
        }
      } else if (toBeRemovedStart < end) {
        answer.push_back(vector<int>({start, toBeRemovedStart}));
        if (toBeRemovedEnd < end) {
          answer.push_back(vector<int>({toBeRemovedEnd, end}));
        }
      } else {
        answer.push_back(vector<int>({start, end}));
      }
    }

    return answer;
  }
};
