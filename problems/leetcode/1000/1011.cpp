// 1011. Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

using namespace std;

#include <vector>

class Solution {
public:
  int MAX_WEIGHT = 500;
  int shipWithinDays(vector<int> &weights, int days) {
    int startWeight = 0, endWeight = MAX_WEIGHT * weights.size();
    for (auto weight : weights) {
      startWeight = max(startWeight, weight);
    }

    while (startWeight < endWeight) {
      int capacity = (startWeight + endWeight) / 2;
      if (isSufficientWithinDays(weights, days, capacity)) {
        endWeight = capacity;
      } else {
        startWeight = capacity + 1;
      }
    }

    return startWeight;
  }

  bool isSufficientWithinDays(vector<int> &weights, int days, int capacity) {
    int currentWeight = 0, currentDays = 1;

    for (auto weight : weights) {
      if (currentWeight + weight > capacity) {
        currentWeight = weight;
        currentDays++;
      } else {
        currentWeight += weight;
      }
    }

    return currentDays <= days;
  }
};
