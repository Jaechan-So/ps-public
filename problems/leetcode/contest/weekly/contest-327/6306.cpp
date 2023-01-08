// 6306. Time to Cross a Bridge
// https://leetcode.com/contest/weekly-contest-327/problems/time-to-cross-a-bridge/
// Result: Accepted

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int findCrossingTime(int n, int k, vector<vector<int>> &time) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        leftWorkers, rightWorkers; // (efficiency, index)
    for (int i = 0; i < k; i++) {
      leftWorkers.push({time[i][0] + time[i][2], i});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pendingLeftWorkers, pendingRightWorkers; // (actiavted timestamp, index)
    int timestamp = 0;

    while (n || !rightWorkers.empty() || !pendingRightWorkers.empty()) {
      while (!pendingLeftWorkers.empty() &&
             pendingLeftWorkers.top().first <= timestamp) {
        int index = pendingLeftWorkers.top().second;
        pendingLeftWorkers.pop();
        leftWorkers.push({time[index][0] + time[index][2], index});
      }
      while (!pendingRightWorkers.empty() &&
             pendingRightWorkers.top().first <= timestamp) {
        int index = pendingRightWorkers.top().second;
        pendingRightWorkers.pop();
        rightWorkers.push({time[index][0] + time[index][2], index});
      }

      if (!rightWorkers.empty()) {
        int index = rightWorkers.top().second;
        rightWorkers.pop();
        pendingLeftWorkers.push(
            {timestamp + time[index][2] + time[index][3], index});
        timestamp += time[index][2];
      } else if (n && !leftWorkers.empty()) {
        int index = leftWorkers.top().second;
        leftWorkers.pop();
        pendingRightWorkers.push(
            {timestamp + time[index][0] + time[index][1], index});
        timestamp += time[index][0];
        n--;
      } else {
        int nextTimestamp = INT_MAX;
        if (!pendingRightWorkers.empty()) {
          nextTimestamp = min(nextTimestamp, pendingRightWorkers.top().first);
        }
        if (!pendingLeftWorkers.empty()) {
          nextTimestamp = min(nextTimestamp, pendingLeftWorkers.top().first);
        }
        timestamp = nextTimestamp;
      }
    }

    return timestamp;
  }
};
