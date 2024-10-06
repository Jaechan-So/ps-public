// 632. Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  set<vector<int>> entries;
  int globalMin = INT_MAX, globalMax = INT_MIN, rangeMin = INT_MAX,
      rangeMax = INT_MIN;

  bool isRangeSmaller(pair<int, int> p1, pair<int, int> p2) {
    return (p1.second - p1.first < p2.second - p2.first) ||
           ((p1.second - p1.first == p2.second - p2.first) &&
            p1.first < p2.first);
  }

  vector<int> smallestRange(vector<vector<int>> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      entries.insert(
          {nums[i][0], nums[i].size() > 1 ? nums[i][1] : INT_MAX, i, 0});
    }
    rangeMin = (*entries.begin())[0];
    rangeMax = (*entries.rbegin())[0];

    while (!entries.empty()) {
      int localMin = min(globalMin, (*entries.begin())[0]),
          localMax = max(globalMax, (*entries.rbegin())[0]);
      if (isRangeSmaller({localMin, localMax}, {rangeMin, rangeMax})) {
        rangeMin = localMin;
        rangeMax = localMax;
      }

      int value = (*entries.begin())[0], nextValue = (*entries.begin())[1],
          bucket = (*entries.begin())[2], nextIndex = (*entries.begin())[3] + 1;
      entries.erase(entries.begin());

      if (nextValue != INT_MAX) {
        entries.insert({nums[bucket][nextIndex],
                        nextIndex + 1 < nums[bucket].size()
                            ? nums[bucket][nextIndex + 1]
                            : INT_MAX,
                        bucket, nextIndex});
      } else {
        globalMin = min(globalMin, value);
        globalMax = max(globalMax, value);
      }
    }

    return {rangeMin, rangeMax};
  }
};

// 1. Naive
// 모든 경우의 수를 다 조사한다.
// O(Phi_(k = 0 to n - 1)(nums[k].size()) * nums.size())

// 2. Sorted Set
// { current, next, bucket, index } 를 담는 Sorted Set을 이용한다.
// 각 bucket에 도달한 경우, 고정점이 되므로 따로 반영한다.
