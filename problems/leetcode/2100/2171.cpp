// 2171. Removing Minimum Number of Magic Beans
// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/

using namespace std;

#include <vector>

class Solution {
public:
  long long minimumRemoval(vector<int> &beans) {
    // After sort, if we consider to set all bags with beans[i],
    sort(beans.begin(), beans.end());

    int n = beans.size();
    long long totalSum = 0;
    for (long long bean : beans) {
      totalSum += bean;
    }

    long long answer = LLONG_MAX, cumulativeSum = 0;
    for (int i = 0; i < n; i++) {
      // 1. beans[0] ~ beans[i - 1] must become 0. -> Prefix Sum
      long long formerRemoval = cumulativeSum;

      // 2. beans[i] ~ beans[n] must be beans[i]. -> Prefix Sum - (n - i) *
      // beans[i]
      long long latterRemoval = (totalSum - cumulativeSum) -
                                ((long long)beans[i] * (long long)(n - i));
      answer = min(answer, formerRemoval + latterRemoval);

      cumulativeSum += beans[i];
    }

    return answer;
  }
};
