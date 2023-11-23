// 1187. Make Array Strictly Increasing
// https://leetcode.com/problems/make-array-strictly-increasing/description/

using namespace std;

#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int n1 = 0;
  vector<unordered_map<int, int>> dp;

  int getMinCost(vector<int> &arr1, set<int> &arr2Set, int i, int prev) {
    if (i == n1) {
      return 0;
    }

    if (dp[i].find(prev) != dp[i].end()) {
      return dp[i][prev];
    }

    int cost = INT_MAX;
    if (arr1[i] > prev) {
      cost = min(cost, getMinCost(arr1, arr2Set, i + 1, arr1[i]));
    }

    set<int>::iterator iter = arr2Set.lower_bound(prev + 1);
    if (iter != arr2Set.end()) {
      int result = getMinCost(arr1, arr2Set, i + 1, *iter);
      if (result != INT_MAX) {
        cost = min(cost, 1 + result);
      }
    }

    dp[i][prev] = cost;
    return dp[i][prev];
  }

  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    n1 = arr1.size();
    dp = vector<unordered_map<int, int>>(n1);
    set<int> arr2Set(arr2.begin(), arr2.end());

    int result = getMinCost(arr1, arr2Set, 0, -1);
    return result == INT_MAX ? -1 : result;
  }
};

// 어차피 Strictly Increasing하게 만들기 위해서는 arr2에서 중복된 원소는 사용할
// 수 없다. 따라서 set으로 만들어서 제거한다. 또한 정렬되어 있으면 좋으므로,
// set을 이용한다. a - b - c 순서에서 b >= c인 항을 발견했을 때, Case 1. b를 a <
// b < c를 만족하도록 바꿔서 해결한다. Case 2. c를 b < c가 만족하도록 바꿔서
// 해결한다. 결과적으로 Case 1이 무조건 유리하다. 왜냐하면, arr2Set에서 사용하게
// 되는 수도 작고, c 항이 더 작아지기 때문이다. 불가능한 경우에만 Case 2를
// 사용한다. Case 2를 사용하는 경우, 뒤 쪽으로 연쇄적으로 영향이 갈 수 있음을
// 유의해야 한다.

// dfs(i, j): arr1의 i번째 인덱스부터 끝까지, 이전 값이 j일 때 필요한 최소 횟수
// -> dfs(0, -1)을 구한다. dfs(i, j) = arr1[i] < j ? 1 + dfs(i + 1, (Binary
// Search로 (prev + 1)의 lower_bound 구하기)) : min(그대로, 혹은 바꾸기)
