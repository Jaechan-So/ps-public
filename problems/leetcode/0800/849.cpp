// 849. Maximize Distance to Closest Person
// https://leetcode.com/problems/maximize-distance-to-closest-person/description/

using namespace std;

#include <vector>

class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    int answer = INT_MAX, prevIndex = -1;

    for (int i = 0; i < seats.size(); i++) {
      if (seats[i] == 1) {
        if (prevIndex == -1) {
          answer = i;
        } else {
          answer = max(answer, (i - prevIndex) / 2);
        }
        prevIndex = i;
      }
    }

    answer = max(answer, (int)seats.size() - 1 - prevIndex);

    return answer;
  }
};
