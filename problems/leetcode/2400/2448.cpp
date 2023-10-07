// 2448. Minimum Cost to Make Array Equal
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

using namespace std;

#include <vector>

class Solution {
public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    int n = nums.size();

    vector<vector<long long>> points;
    for (int i = 0; i < n; i++) {
      points.push_back({nums[i], cost[i]});
    }
    sort(points.begin(), points.end());

    long long slope = 0, yIntercept = 0;
    for (int i = 0; i < n; i++) {
      slope -= cost[i];
      yIntercept += ((long long)cost[i] * (long long)nums[i]);
    }

    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      slope += (2 * points[i][1]);
      yIntercept -= (2 * points[i][0] * points[i][1]);
      result = min(result, (slope * points[i][0] + yIntercept));
    }

    return result;
  }
};

// 같아지는 수를 x라고 했을 때,
// sum(abs(x - nums[i]) * cost[i]) 가 최소가 되는 x를 찾아야 함.
// 각 nums[i]에서, 기울기는 2 * cost[i]가 더해지고, y절편은 2 * cost[i] *
// nums[i]가 빼짐.
