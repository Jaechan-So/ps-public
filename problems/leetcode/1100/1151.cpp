// 1151. Minimum Swaps to Group All 1's Together
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/description

using namespace std;

#include <vector>

class Solution {
public:
  int minSwaps(vector<int> &data) {
    int n = data.size();

    int numberOfOne = 0;
    for (int d : data) {
      if (d == 1) {
        numberOfOne++;
      }
    }
    if (numberOfOne <= 1) {
      return 0;
    }

    int numberOfZero = 0;
    for (int i = 0; i < numberOfOne; i++) {
      if (data[i] == 0) {
        numberOfZero++;
      }
    }

    int minNumberOfZero = numberOfZero;
    for (int i = 1; i <= n - numberOfOne; i++) {
      if (data[i - 1] == 0) {
        numberOfZero--;
      }
      if (data[i + numberOfOne - 1] == 0) {
        numberOfZero++;
      }
      minNumberOfZero = min(minNumberOfZero, numberOfZero);
    }

    return minNumberOfZero;
  }
};
