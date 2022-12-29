// 740. Delete and Earn
// https://leetcode.com/problems/delete-and-earn/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    // 1. Get count of each distinct point. This can be done since an order of
    // each point does not matter.
    map<int, int> pointCounts;
    for (int i = 0; i < nums.size(); i++) {
      pointCounts[nums[i]]++;
    }

    int maxPoint = 0, lastPoint = pointCounts.begin()->first - 1;
    vector<int> consecutiveTotalPoints;
    for (pair<int, int> p : pointCounts) {
      int point = p.first, count = p.second;
      if (lastPoint + 1 != point) {
        // 2. If we found consecutive interval of points, then we get maximum
        // points from the interval.
        maxPoint += getLocalMaxPoint(consecutiveTotalPoints);
        consecutiveTotalPoints.clear();
      }
      consecutiveTotalPoints.push_back(point * count);
      lastPoint = point;
    }

    maxPoint += getLocalMaxPoint(consecutiveTotalPoints);

    return maxPoint;
  }

  // 3. In the interval, we can get maximum points from the interval by dynamic
  // programming.
  int getLocalMaxPoint(vector<int> &consecutiveTotalPoints) {
    if (consecutiveTotalPoints.size() == 0) {
      return 0;
    }

    if (consecutiveTotalPoints.size() == 1) {
      return consecutiveTotalPoints[0];
    }

    vector<int> cumulativeMaxPoints;
    cumulativeMaxPoints.push_back(consecutiveTotalPoints[0]);
    cumulativeMaxPoints.push_back(
        max(consecutiveTotalPoints[0], consecutiveTotalPoints[1]));

    for (int i = 2; i < consecutiveTotalPoints.size(); i++) {
      cumulativeMaxPoints.push_back(
          max(cumulativeMaxPoints[i - 2] + consecutiveTotalPoints[i],
              cumulativeMaxPoints[i - 1]));
    }

    return cumulativeMaxPoints[consecutiveTotalPoints.size() - 1];
  }
};
