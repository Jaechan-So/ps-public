// 502. IPO
// https://leetcode.com/problems/ipo/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    int n = profits.size();
    vector<vector<int>> projects;
    for (int i = 0; i < n; i++) {
      projects.push_back({capital[i], profits[i]});
    }
    sort(projects.begin(), projects.end());
    int index = 0;

    priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;
    while (index < n && projects[index][0] <= w) {
      pq.push({projects[index][1], projects[index][0]});
      index++;
    }

    while (!pq.empty() && k > 0) {
      w += pq.top()[0];
      pq.pop();
      k--;

      while (index < n && projects[index][0] <= w) {
        pq.push({projects[index][1], projects[index][0]});
        index++;
      }
    }

    return w;
  }
};

// 1. capital 오름차순으로 정렬한다.
// 2. 현재 capital로 가능한 것들을 Priority Queue에 넣는다. 이 때 profit이 큰
// 것이 위로 가게 넣는다.
// 3. 하나를 뺀 뒤 바뀐 capital을 반영한다.
// 4. 위를 k만큼 반복한다.
