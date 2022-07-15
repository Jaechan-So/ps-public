// 582. Kill Process
// https://leetcode.com/problems/kill-process/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
    unordered_map<int, vector<int>> processes;
    int total = pid.size();
    for (int i = 0; i < total; i++) {
      int childPid = pid[i];
      int parentPid = ppid[i];
      if (processes.find(parentPid) != processes.end()) {
        processes[parentPid].push_back(childPid);
      } else {
        vector<int> childs(1, childPid);
        processes.insert(make_pair(parentPid, childs));
      }
    }

    queue<int> remainingTargets;
    remainingTargets.push(kill);

    vector<int> killTargets;

    while (!remainingTargets.empty()) {
      int currentTarget = remainingTargets.front();
      remainingTargets.pop();
      killTargets.push_back(currentTarget);

      if (processes.find(currentTarget) != processes.end()) {
        for (auto child : processes[currentTarget]) {
          remainingTargets.push(child);
        }
      }
    }

    return killTargets;
  }
};
