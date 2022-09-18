// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> answer;

    sort(intervals.begin(), intervals.end());
    answer.push_back(intervals[0]);

    int cur = 0;
    for (int i = 1; i < intervals.size(); i++) {
      if (answer[cur][1] < intervals[i][0]) {
        answer.push_back(intervals[i]);
        cur++;
      } else {
        answer[cur][1] = max(answer[cur][1], intervals[i][1]);
      }
    }

    return answer;
  }
};
