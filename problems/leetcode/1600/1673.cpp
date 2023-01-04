// 1673. Find the Most Competitive Subsequence
// https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> competitiveSubsequence;
    int n = nums.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        remainingNums;
    priority_queue<int, vector<int>, greater<int>> pendingNumRemovals;

    // Start range is [0, n - k - 1], since index which is greater or equal to n
    // - k cannot get subsequence with total length k.
    for (int i = 0; i <= n - k - 1; i++) {
      remainingNums.push({nums[i], i});
    }

    int prevIndex = 0;
    for (int i = 0; i < k; i++) {
      remainingNums.push({nums[n - k + i], n - k + i});

      // Find minimum number and index within current index range, [prevIndex, n
      // - k + i].
      pair<int, int> currentNumAndIndex = remainingNums.top();
      int num = currentNumAndIndex.first, index = currentNumAndIndex.second;

      // Minimum number will construct most competitive sequence.
      competitiveSubsequence.push_back(num);

      // Lazily remove numbers which are outside of competitive subsequence
      // candidates.
      for (int j = prevIndex; j <= index; j++) {
        pendingNumRemovals.push(nums[j]);
      }

      while (!pendingNumRemovals.empty()) {
        int smallestRemainingNum = remainingNums.top().first,
            smallestPendingNumRemoval = pendingNumRemovals.top();
        if (smallestRemainingNum > smallestPendingNumRemoval) {
          // If the smallest pending number removal is smaller, then drop it.
          // (We do not neede it in future)
          pendingNumRemovals.pop();
        } else if (smallestRemainingNum == smallestPendingNumRemoval) {
          // If the smallest pending number removal is equal to the smallest
          // remaining number, then remove in both priority queue since it
          // locates outside of competitive subsequence candidates.
          remainingNums.pop();
          pendingNumRemovals.pop();
        } else {
          // If the smallest pending number removal is bigger, then we may need
          // this in future. Keep them in priority queue.
          break;
        }
      }

      prevIndex = index + 1;
    }

    return competitiveSubsequence;
  }
};

// n = nums.size()
// index 0부터 n - k + 1까지 대상으로 가장 작은 값을 찾음. 만약 같은 값을 가지면
// 인덱스가 작은 걸 우선순위로. 찾은 인덱스를 s1이라고 하면, s1부터 n - k +
// 2까지 대상으로 가장 작은 값을 찾음.
// ... 반복
// 각 인덱스에 해당하는 숫자를 기록하면 끝
// 으로 하게 되면, 가장 작은 값을 찾는 과정이 O(n)만큼 걸리게 됨. 따라서 전체
// 과정이 O(nk)의 시간 복잡도를 가지게 되어 TLE가 뜰 듯. 따라서 가장 작은 값을
// 찾는 과정을 줄여야 하는데 구간별 작은 값을 미리 저장한다던지 해서 시간
// 복잡도를 줄일 수 있나? 미리 처음에 0부터 n - k + 1까지 값들을 priority_queue
// 안에 담아두고 다음 구간이 정해지면, 제외되는 값들을 찾아서 priority_queue에서
// lazy하게 뺄 수 있다. 따라서 전체 시간복잡도 O(nlogn)으로 해결 가능
