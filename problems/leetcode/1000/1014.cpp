// 1014. Best Sightseeing Pair
// https://leetcode.com/problems/best-sightseeing-pair/

using namespace std;

#include <vector>

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int maximumSum = values[0], maximumScore = 0;

    for (int i = 1; i < values.size(); i++) {
      maximumScore = max(maximumScore, maximumSum + values[i] - i);
      maximumSum = max(maximumSum, values[i] + i);
    }

    return maximumScore;
  }
};
