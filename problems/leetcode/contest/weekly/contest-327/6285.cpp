// 6285. Maximal Score After Applying K Operations
// https://leetcode.com/contest/weekly-contest-327/problems/maximal-score-after-applying-k-operations/
// Result: Accepted (with Wrong Answer 1 time)

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  long long maxKelements(vector<int> &nums, int k) {
    long long score = 0;

    priority_queue<int, vector<int>, less<int>> scorePq;
    for (int num : nums) {
      scorePq.push(num);
    }

    for (int i = 0; i < k; i++) {
      int incremental = scorePq.top();
      scorePq.pop();

      score += incremental;

      scorePq.push(ceilFunc(incremental));
    }

    return score;
  }

  int ceilFunc(int i) { return (i % 3 == 0) ? (i / 3) : (i / 3) + 1; }
};
