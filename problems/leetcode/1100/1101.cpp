// 1101. The Earliest Moment When Everyone Become Friends
// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int earliestAcq(vector<vector<int>> &logs, int n) {
    int leadingPersonNumber[100];
    for (int i = 0; i < n; i++) {
      leadingPersonNumber[i] = -1;
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (auto &log : logs) {
      pq.push(log);
    }

    int totalFriends = 0;
    while (!pq.empty()) {
      vector<int> log = pq.top();
      pq.pop();
      int timestamp = log[0], x = log[1], y = log[2];

      if (leadingPersonNumber[x] == -1 && leadingPersonNumber[y] == -1) {
        leadingPersonNumber[x] = x;
        leadingPersonNumber[y] = x;
        totalFriends += 2;
      } else if (leadingPersonNumber[x] == -1 && leadingPersonNumber[y] != -1) {
        leadingPersonNumber[x] = leadingPersonNumber[y];
        totalFriends++;
      } else if (leadingPersonNumber[x] != -1 && leadingPersonNumber[y] == -1) {
        leadingPersonNumber[y] = leadingPersonNumber[x];
        totalFriends++;
      } else {
        int leaderForX = leadingPersonNumber[x],
            leaderForY = leadingPersonNumber[y];

        if (leaderForX != leaderForY) {
          for (int i = 0; i < n; i++) {
            if (leadingPersonNumber[i] == leaderForY) {
              leadingPersonNumber[i] = leaderForX;
            }
          }
        }
      }

      if (totalFriends == n) {
        int leader = leadingPersonNumber[0];
        bool isLeaderUnique = true;

        for (int i = 0; i < n; i++) {
          if (leadingPersonNumber[i] != leader) {
            isLeaderUnique = false;
            break;
          }
        }

        if (isLeaderUnique) {
          return timestamp;
        }
      }
    }

    return -1;
  }
};
