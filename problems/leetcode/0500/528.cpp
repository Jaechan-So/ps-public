// 528. Random Pick with Weight
// https://leetcode.com/problems/random-pick-with-weight/

using namespace std;

#include <random>
#include <vector>

class Solution {
public:
  vector<long long> prefixSum;
  long long totalSum;
  uniform_int_distribution<long long> distribution;
  default_random_engine generator;

  Solution(vector<int> &w) {
    long long sum = 0;
    for (int i = 0; i < w.size(); i++) {
      sum += w[i];
      prefixSum.push_back(sum);
    }
    totalSum = sum;
    distribution = uniform_int_distribution<long long>(1, totalSum);
  }

  int pickIndex() {
    long long result = distribution(generator);
    vector<long long>::iterator iter =
        lower_bound(prefixSum.begin(), prefixSum.end(), result);

    return (int)(iter - prefixSum.begin());
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
