// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/description/

using namespace std;

#include <vector>

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int taskCounts[26] = {
        0,
    };
    for (int i = 0; i < tasks.size(); i++) {
      taskCounts[charToIndex(tasks[i])]++;
    }

    int maxTaskCount = *max_element(taskCounts, taskCounts + 26);

    int maxTaskSortCount = 0;
    for (int i = 0; i < 26; i++) {
      if (taskCounts[i] == maxTaskCount) {
        maxTaskSortCount++;
      }
    }

    if (maxTaskSortCount - 1 >= n) {
      return tasks.size();
    }

    if ((n - maxTaskSortCount + 1) * (maxTaskCount - 1) <
        tasks.size() - (maxTaskCount * maxTaskSortCount)) {
      return tasks.size();
    }

    return (maxTaskSortCount - 1) + n * (maxTaskCount - 1) + maxTaskCount;
  }

  int charToIndex(char ch) { return ch - 'A'; }
};
