// 1606. Find Servers That Handled Most Number of Requests
// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

using namespace std;

#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
    vector<int> answer;

    int workCount = arrival.size();
    unordered_map<int, int> serverWorkCounts;
    set<int> availableServers;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        busyServers;

    for (int i = 0; i < k && i < workCount; i++) {
      serverWorkCounts[i]++;

      int endTimeStamp = arrival[i] + load[i];
      busyServers.push({endTimeStamp, i});
    }

    for (int i = k; i < workCount; i++) {
      int endTimeStamp = arrival[i] + load[i];

      while (!busyServers.empty() && busyServers.top().first <= arrival[i]) {
        availableServers.insert(busyServers.top().second);
        busyServers.pop();
      }

      if (!availableServers.empty()) {
        auto iter = lower_bound(availableServers.begin(),
                                availableServers.end(), i % k);
        iter =
            (iter == availableServers.end() ? availableServers.begin() : iter);
        int assignedServerId = *iter;

        busyServers.push({endTimeStamp, assignedServerId});
        availableServers.erase(assignedServerId);
        serverWorkCounts[assignedServerId]++;
      }
    }

    int maxCount = 0;
    for (auto &server : serverWorkCounts) {
      if (server.second > maxCount) {
        maxCount = server.second;
        answer.clear();
        answer.push_back(server.first);
      } else if (server.second == maxCount) {
        answer.push_back(server.first);
      }
    }

    return answer;
  }
};
