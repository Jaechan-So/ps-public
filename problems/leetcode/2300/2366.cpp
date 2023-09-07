// 2366. Minimum Replacements to Sort the Array
// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

using namespace std;

#include <vector>

class Solution {
public:
  long long minimumReplacement(vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }

    int n = nums.size(), next = nums.back();
    long long replacement = 0;
    for (int i = n - 2; i >= 0; i--) {
      int current = nums[i];

      if (current > next) {
        int bunch = current % next == 0 ? current / next : (current / next) + 1;
        replacement += bunch - 1;
        next = current / bunch;
      } else {
        next = current;
      }
    }

    return replacement;
  }
};

// 어떤 수를 쪼개면 작아지므로, 오른쪽에 있는 수일수록 안 쪼개는 것이 유리할
// 것임. (만약 오른쪽 수를 쪼개서 가능한 경우라면 안 쪼개도 가능할테니까)
// 오른쪽에서 왼쪽으로 오면서, 이전 수보다 더 큰 수를 만나게 되면 쪼개야 함.
// 왼쪽을 m, 오른쪽을 n이라고 했을 때 (m > n) 쪼갰을 때 가장 왼쪽의 수가
// 결국에는 다음 번에는 오른쪽 수가 되니까 클 수록 유리함. 따라서 가장 마지막에
// 쪼갰을 때 커지도록 쪼개야 함. (m / k) + (m % k == 0 ? 0 : 1) <= n 을 만족하는
// k에 대해서, (k >= 2) (m / k)가 최대가 되도록 해야 한다. 즉 k가 최소가 되어야
// 한다. 다음 값은 (m / k), replacement += k이다. m = n * q + r이라고 하면, (q +
// (r == 0 ? 0 : 1)) 묶음으로 쪼갰을 때 m = n * (q + 1) - n + r, 즉 (n - r) 개
// 만큼은 (n - 1). 만약 (q + 1) < (n - r)인 경우가 나온다면 이렇게 불가능하다고
// 볼 수 있음. 이 규칙까지 한꺼번에 하기 위해서는 Binary Search 방식으로 가야할
// 것 같다.
