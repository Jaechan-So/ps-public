// 2551. Put Marbles in Bags
// https://leetcode.com/problems/put-marbles-in-bags/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    long long minScore = weights.front() + weights.back(),
              maxScore = weights.front() + weights.back();
    vector<int> adjacentScoreSums;

    for (int i = 0; i < weights.size() - 1; i++) {
      adjacentScoreSums.push_back(weights[i] + weights[i + 1]);
    }
    int n = adjacentScoreSums.size();
    sort(adjacentScoreSums.begin(), adjacentScoreSums.end());

    for (int i = 0; i < k - 1; i++) {
      minScore += adjacentScoreSums[i];
      maxScore += adjacentScoreSums[n - 1 - i];
    }

    return maxScore - minScore;
  }
};

// 1. Naive
// 주어진 weights를 두 묶음으로 나눈다고 하고, 이 때 각 묶음을 각각 i, k - i개로
// 나누는 경우를 생각한 뒤, 각각의 min + min과 max + max가 정답이 될 것 이다.
// 여기서 문제는, 두 묶음으로 나누는 경우가 O(n)이고 묶음의 i를 정하는 경우의
// 수가 약 O(k)이므로, 실질적으로 O(n^2)의 알고리즘이다.

// 2. 하나씩 추가하기
// 경계를 하나씩 추가한다는 개념으로 접근하면, 경계 양 쪽에 있는 원소를 합하게
// 된다. 따라서, 각각의 경계를 낮은 순으로 고르는 방법과 높은 순으로 고르는
// 방법을 찾을 수 있다. 총 (k - 1)개의 경계를 고르는 것으로 접근할 수 있고, 이
// 때 양 끝은 무조건 포함된다.
