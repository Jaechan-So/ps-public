// 1229. Meeting Scheduler
// https://leetcode.com/problems/meeting-scheduler/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> minAvailableDuration(vector<vector<int>> &slots1,
                                   vector<vector<int>> &slots2, int duration) {
    sort(slots1.begin(), slots1.end());
    sort(slots2.begin(), slots2.end());

    int index1 = 0, index2 = 0;

    while (index1 < slots1.size() && index2 < slots2.size()) {
      int start1 = slots1[index1][0], end1 = slots1[index1][1],
          start2 = slots2[index2][0], end2 = slots2[index2][1];
      if (!hasIntersection(start1, end1, start2, end2)) {
        if (end1 <= end2) {
          index1++;
        } else {
          index2++;
        }
      } else {
        int start = max(start1, start2), end = min(end1, end2);
        if (end - start >= duration) {
          return vector<int>({start, start + duration});
        }

        if (end1 <= end2) {
          index1++;
        } else {
          index2++;
        }
      }
    }

    while (index1 < slots1.size()) {
      if (index2 == slots2.size()) {
        index2--;
      }
      int start1 = slots1[index1][0], end1 = slots1[index1][1],
          start2 = slots2[index2][0], end2 = slots2[index2][1];
      if (!hasIntersection(start1, end1, start2, end2)) {
        index1++;
      } else {
        int start = max(start1, start2), end = min(end1, end2);
        if (end - start >= duration) {
          return vector<int>({start, start + duration});
        }

        index1++;
      }
    }

    while (index2 < slots2.size()) {
      if (index1 == slots1.size()) {
        index1--;
      }
      int start1 = slots1[index1][0], end1 = slots1[index1][1],
          start2 = slots2[index2][0], end2 = slots2[index2][1];
      if (!hasIntersection(start1, end1, start2, end2)) {
        index2++;
      } else {
        int start = max(start1, start2), end = min(end1, end2);
        if (end - start >= duration) {
          return vector<int>({start, start + duration});
        }

        index2++;
      }
    }

    return vector<int>();
  }

  bool hasIntersection(int start1, int end1, int start2, int end2) {
    int start = max(start1, start2), end = min(end1, end2);
    return start <= end;
  }
};
