// 1834. Single-Threaded CPU
// https://leetcode.com/problems/single-threaded-cpu/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        availableTasks; // { processingTime, index }
    for (int i = 0; i < tasks.size(); i++) {
      tasks[i].push_back(i);
    }
    sort(tasks.begin(), tasks.end());

    int pendingIndex = 1;
    long long time = tasks[0][0];
    availableTasks.push({tasks[0][1], tasks[0][2]});

    vector<int> schedule;
    while (!availableTasks.empty()) {
      int processingTime = availableTasks.top().first,
          index = availableTasks.top().second;
      schedule.push_back(index);
      availableTasks.pop();
      time += processingTime;

      if (availableTasks.empty() && pendingIndex < tasks.size()) {
        time = max(time, (long long)tasks[pendingIndex][0]);
      }

      while (pendingIndex < tasks.size() && tasks[pendingIndex][0] <= time) {
        availableTasks.push({tasks[pendingIndex][1], tasks[pendingIndex][2]});
        pendingIndex++;
      }
    }

    return schedule;
  }
};
