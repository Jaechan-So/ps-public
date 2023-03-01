// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    int newIntervalStart = newInterval[0], newIntervalEnd = newInterval[1];
    bool isNewIntervalInserted = false;

    vector<vector<int>> newIntervals;

    for (int i = 0; i < intervals.size(); i++) {
      int intervalStart = intervals[i][0], intervalEnd = intervals[i][1];

      if (intervalEnd < newIntervalStart) {
        newIntervals.push_back(vector<int>({intervalStart, intervalEnd}));
        continue;
      }

      if (intervalStart > newIntervalEnd) {
        if (!isNewIntervalInserted) {
          newIntervals.push_back(newInterval);
          isNewIntervalInserted = true;
        }
        newIntervals.push_back(intervals[i]);
        continue;
      }

      isNewIntervalInserted = true;

      int mergedIntervalStart = min(intervalStart, newIntervalStart);

      i++;
      while (i < intervals.size()) {
        if (intervals[i][0] > newIntervalEnd) {
          break;
        }
        i++;
      }
      i--;

      int mergedIntervalEnd = max(intervals[i][1], newIntervalEnd);

      newIntervals.push_back(
          vector<int>({mergedIntervalStart, mergedIntervalEnd}));
    }

    if (newIntervals.empty() || newIntervals.back()[1] < newIntervalStart) {
      newIntervals.push_back(newInterval);
    }

    return newIntervals;
  }
};

// 1. 각 interval의 end_i를 조사해서 겹치는 범위가 있는지 찾았을 때, 있는 경우
// 1-1. 어차피 interval은 이미 정렬이 되어 있기 때문에, 처음 겹치는 친구만
// 찾으면 됨 1-2. 처음 겹치는 친구의 start가 merged interval의 시작이 됨 1-3.
// newInterval의 end를 기준으로, 각 interval의 start_i를 조사해서 겹치는 범위의
// 끝을 정할 수 있음. max(마지막으로 겹치는 interval의 end_i, newInterval_end),
// 없으면 자동적으로 newInterval_end
// 2. 각 interval의 end_i를 조사해서 겹치는 범위가 있는지 찾았을 때, 없는 경우
// 2-1. newInterval의 start가 merged intertval의 시작이 됨
// 2-2. newInterval의 end를 기준으로, 각 interval의 start_i를 조사해서 겹치는
// 범위의 끝을 정할 수 있음.
