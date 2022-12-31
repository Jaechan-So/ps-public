// 452. Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

using namespace std;

#include <vector>

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // 1. Sort each points by ascending order of starting point.
    sort(points.begin(), points.end());

    int shots = 0;
    pair<int, int> currentIntersection = {points[0][0], points[0][1]};

    for (int i = 1; i < points.size(); i++) {
      pair<int, int> currentPoint = {points[i][0], points[i][1]};

      // 2. For each point, if there is an intersection with current
      // intersection, then get cumulative intersection.
      if (isIntersected(currentIntersection, currentPoint)) {
        currentIntersection =
            getIntersection(currentIntersection, currentPoint);
      } else {
        // 3. Otherwise, we can treat this situation as previous cumulative
        // points can be burst in a single shot. so add one shot and set next
        // cumulative intersection.
        shots++;
        currentIntersection = {currentPoint.first, currentPoint.second};
      }
    }

    return shots + 1;
  }

  bool isIntersected(pair<int, int> point1, pair<int, int> point2) {
    return !isSeparated(point1, point2);
  }

  bool isSeparated(pair<int, int> point1, pair<int, int> point2) {
    if (point1.second < point2.first) {
      return true;
    }

    if (point2.second < point1.first) {
      return true;
    }

    return false;
  }

  // 4. Fortunately, getting intersection between two point can be done by easy
  // function.
  pair<int, int> getIntersection(pair<int, int> point1, pair<int, int> point2) {
    return {max(point1.first, point2.first), min(point1.second, point2.second)};
  }
};
