// 2251. Number of Flowers in Full Bloom
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &people) {
    int m = flowers.size(), n = people.size();

    vector<vector<int>> transitions;
    for (int i = 0; i < m; i++) {
      int start = flowers[i][0], end = flowers[i][1];
      transitions.push_back({start, 1});
      transitions.push_back({end + 1, -1});
    }
    sort(transitions.begin(), transitions.end());

    vector<vector<int>> peopleAndTimes;
    for (int i = 0; i < n; i++) {
      peopleAndTimes.push_back({people[i], i});
    }
    sort(peopleAndTimes.begin(), peopleAndTimes.end());

    vector<int> fullBlooms(n, 0);
    int transitionIndex = 0, currentBlooms = 0;
    for (int i = 0; i < n; i++) {
      while (transitionIndex < transitions.size() &&
             transitions[transitionIndex][0] <= peopleAndTimes[i][0]) {
        currentBlooms += transitions[transitionIndex++][1];
      }
      fullBlooms[peopleAndTimes[i][1]] = currentBlooms;
    }

    return fullBlooms;
  }
};

// 1. Prefix Sum을 이용한다.
// 2. 어떤 배열 A가 있을 때, A에 대한 Prefix Sum에 대해 [start, end] 범위에 x를
// 더하기 위해서는 A[start]에 x를 더하고, A[end + 1]에서 x를 빼면 된다.
// 3. 이를 이용해서, 각각의 flowers를 순회하면서 A를 구성한다. 여기서 x ==
// 1이다.
// 4. A에 대한 Prefix Sum을 구한다.
// 5. 각 people에 대해서, A[people[i]]를 구한다.

// 위의 방법은 Memory Limit이 나기 때문에, 정렬 or Priority Queue를 사용해서
// 개선한다.
