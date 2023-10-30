// 2009. Minimum Number of Operations to Make Array Continuous
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  int lowerBound(vector<int> &nums, int val) {
    if (nums.back() < val) {
      return nums.size();
    }

    int start = 0, end = nums.size() - 1;

    while (start < end) {
      int mid = (start + end) / 2;

      if (nums[mid] < val) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return end;
  }

  int minOperations(vector<int> &nums) {
    int n = nums.size();

    unordered_set<int> numSet(nums.begin(), nums.end());
    vector<int> numsWithoutDuplicate(numSet.begin(), numSet.end());
    sort(numsWithoutDuplicate.begin(), numsWithoutDuplicate.end());
    int m = numsWithoutDuplicate.size();

    int operations = INT_MAX;
    for (int i = 0; i < m; i++) {
      int nextIndex =
          lowerBound(numsWithoutDuplicate, numsWithoutDuplicate[i] + n);
      operations = min(operations, n - (nextIndex - i));
    }

    return operations;
  }
};

// nums 안의 어떤 수 하나를 기준으로 잡으면, 이 수가 범위 내의 어떤 수라고
// 생각할 수 있다. 해당 Window 안에서 비어 있는 곳, 즉 nums 안에 존재하지 않는
// 수의 개수를 최소로 하는, 즉 Window에 포함된 nums의 수를 최대한 많게 하면
// 된다.

// i. nums를 정렬한다.
// ii. 각 원소 x에 대해, lower_bound(x + n)을 찾는다. 그러면, x가 가장 왼쪽에
// 있는 Window에서는 x의 위치와 lower_bound의 위치 차이만큼의 개수가 들어가
// 있다. 단, 중복을 고려해야 한다. 따라서, 원소 자체를 중복을 제거해주어야 한다.
