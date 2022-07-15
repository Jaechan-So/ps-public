// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        sortedIntervals;
    for (auto &interval : intervals) {
      sortedIntervals.push(interval);
    }

    priority_queue<int, vector<int>, greater<int>> idleMeetingRoomTimes;

    while (!sortedIntervals.empty()) {
      vector<int> currentInterval = sortedIntervals.top();
      sortedIntervals.pop();

      int start = currentInterval[0], end = currentInterval[1];
      if (!idleMeetingRoomTimes.empty() &&
          idleMeetingRoomTimes.top() <= start) {
        idleMeetingRoomTimes.pop();
        idleMeetingRoomTimes.push(end);
      } else {
        idleMeetingRoomTimes.push(end);
      }
    }

    return idleMeetingRoomTimes.size();
  }
};
