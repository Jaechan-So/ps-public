// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/description/

using namespace std;

#include <vector>

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    int start = 0, end = 1, erase = 0;
    while (end < n) {
      int left1 = intervals[start][0], right1 = intervals[start][1],
          left2 = intervals[end][0], right2 = intervals[end][1];

      if (left2 < right1) {
        erase++;
        if (right2 < right1) {
          start = end;
        }
      } else {
        start = end;
      }

      end++;
    }

    return erase;
  }
};

// 1. intervals를 시작점 기준으로 오름차순 정렬
// 2. start, end 포인터를 이용해서 아래와 같은 순서대로 실행
//    i. 만약 start interval과 end interval이 겹치면, 끝 점이 더 높은 쪽을
//    제거할수록 유리함. ii. 만약 겹치지 않으면, start 포인터를 end 포인터로
//    교체할 수 있음.
