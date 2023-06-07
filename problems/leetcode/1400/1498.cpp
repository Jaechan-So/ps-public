// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

using namespace std;

#include <algorithm>
#include <vector>

class Solution {
public:
  const int mod = 1e9 + 7;

  int numSubseq(vector<int> &nums, int target) {
    int n = nums.size();

    vector<long long> remainders;
    remainders.push_back(1);
    for (int i = 1; i <= n; i++) {
      remainders.push_back((remainders.back() * 2) % mod);
    }

    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());

    int prevLeft = -1, left = -1, right = n - 1;
    long long num = 0;
    while (left <= right) {
      while (left + 1 <= right && sorted[left + 1] + sorted[right] <= target) {
        left++;
      }
      if (left < 0) {
        right--;
        continue;
      }

      int leftCount = left - prevLeft, rightCount = right - left;
      num =
          (num + ((remainders[leftCount] - 1) * remainders[rightCount]) % mod) %
          mod;

      prevLeft = left;
      right--;
    }

    return (int)(num % mod);
  }
};

// DP 접근을 기본적으로 생각 -> 어차피 순서가 상관 없으니, 정렬하고 생각할 수
// 있음 큰 쪽에서부터 생각해볼 수 있음 그럼 최소값은 왼쪽부터 오른쪽으로 오는
// 구조 (처음 ~ 최소값) 개수 -> 2^n - 1, 최소값 오른쪽부터 최대값까지 -> 2^n
// 2^(30p + q)
