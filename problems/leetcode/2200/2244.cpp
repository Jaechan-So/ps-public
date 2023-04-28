// 2244. Minimum Rounds to Complete All Tasks
// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int getMinRound(int n) {
    if (n <= 3) {
      return 1;
    } else if (n <= 5) {
      return 2;
    }

    return (n / 3) + ((n % 3 != 0) ? 1 : 0);
  }

  int minimumRounds(vector<int> &tasks) {
    map<int, int> taskCounts;
    int maxCount = INT_MIN;
    for (int &task : tasks) {
      taskCounts[task]++;
      maxCount = max(maxCount, taskCounts[task]);
    }

    int rounds = 0;
    for (pair<int, int> p : taskCounts) {
      int count = p.second;
      if (count == 1) {
        return -1;
      }
      rounds += getMinRound(count);
    }
    return rounds;
  }
};
