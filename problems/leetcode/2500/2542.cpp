// 2542. Maximum Subsequence Score
// https://leetcode.com/problems/maximum-subsequence-score/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();

    vector<pair<int, int>> sortedNums2;
    for (int i = 0; i < n; i++) {
      sortedNums2.push_back({nums2[i], i});
    }
    sort(sortedNums2.begin(), sortedNums2.end(), less<pair<int, int>>());

    vector<pair<int, int>> sortedNums1;
    for (int i = 1; i < n; i++) {
      int originalIndex = sortedNums2[i].second,
          connectedNum1 = nums1[originalIndex];
      sortedNums1.push_back({connectedNum1, i});
    }
    sort(sortedNums1.begin(), sortedNums1.end(), greater<pair<int, int>>());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k - 1; i++) {
      pq.push(sortedNums1[i].second);
    }
    int nextMaxIndex = k - 1;

    long long sum = 0;
    for (int i = 0; i < k - 1; i++) {
      sum += sortedNums1[i].first;
    }

    long long score = 0;
    for (int i = 0; i < n - k + 1; i++) {
      int originalIndex = sortedNums2[i].second, num1 = nums1[originalIndex],
          num2 = nums2[originalIndex];

      if (!pq.empty() && pq.top() <= i) {
        sum += (sortedNums1[nextMaxIndex].first -
                nums1[sortedNums2[pq.top()].second]);
        pq.pop();
        pq.push(sortedNums1[nextMaxIndex].second);
        do {
          nextMaxIndex++;
        } while (nextMaxIndex < sortedNums1.size() &&
                 sortedNums1[nextMaxIndex].second <= i);
      }

      long long currentScore = (num1 + sum) * num2;
      score = max(score, currentScore);
    }

    return score;
  }
};

// 1. nums2를 크기대로 정렬하여, 최소값을 가장 왼쪽에 있는 값으로 사용할 수
// 있도록 한다.
// 2. nums1을 1과 동일한 순서로 맞춘다.
// 3. nums1을 내림차순 정렬한 vector를 하나 만든다.
// 4. 3번으로부터 현재 유효한 인덱스를 가지는 큰 순서로 k - 1개의 원소를 가지는
// priority_queue를 하나 만든다. 여기서 인덱스는 1,2에서 정렬한 인덱스이다.
