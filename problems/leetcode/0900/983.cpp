// 983. Minimum Cost For Tickets
// https://leetcode.com/problems/minimum-cost-for-tickets/description/

using namespace std;

#include <vector>

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> minCosts = {*min_element(costs.begin(), costs.end())};

    for (int i = 1; i < days.size(); i++) {
      int oneDayPassCost = minCosts.back() + costs[0];

      int sevenDaysPassCost = 0;
      vector<int>::iterator sevenDaysIter =
          lower_bound(days.begin(), days.end(), days[i] - 6);
      if (sevenDaysIter - days.begin() == i) {
        sevenDaysPassCost = minCosts.back() + costs[1];
      } else {
        int targetIndex = sevenDaysIter - days.begin();
        sevenDaysPassCost =
            (targetIndex == 0 ? 0 : minCosts[targetIndex - 1]) + costs[1];
      }

      int thirtyDaysPassCost = 0;
      vector<int>::iterator thirtyDaysIter =
          lower_bound(days.begin(), days.end(), days[i] - 29);
      if (thirtyDaysIter - days.begin() == i) {
        thirtyDaysPassCost = minCosts.back() + costs[2];
      } else {
        int targetIndex = thirtyDaysIter - days.begin();
        thirtyDaysPassCost =
            (targetIndex == 0 ? 0 : minCosts[targetIndex - 1]) + costs[2];
      }

      minCosts.push_back(
          min(oneDayPassCost, min(sevenDaysPassCost, thirtyDaysPassCost)));
    }

    return minCosts.back();
  }
};
