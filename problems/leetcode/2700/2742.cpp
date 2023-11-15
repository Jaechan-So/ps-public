// 2742. Painting the Walls
// https://leetcode.com/problems/painting-the-walls/description/

using namespace std;

#include <vector>

class Solution {
public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    vector<int> minCosts(n + 1, INT_MAX);
    minCosts[0] = 0;

    for (int i = 0; i < n; i++) {
      vector<int> newMinCosts(minCosts);

      for (int w = 0; w <= n; w++) {
        if (minCosts[w] != INT_MAX) {
          int index = min(w + 1 + time[i], n);
          newMinCosts[index] = min(newMinCosts[index], cost[i] + minCosts[w]);
        }
      }

      minCosts = newMinCosts;
    }

    return minCosts[n];
  }
};

// 1. paid는 우리가 돈을 지불해야 하므로 cost per time이 낮은 것부터 순차적으로
// 작업하고, free는 돈을 지불할 필요가 없으므로 cost per time이 높은 것부터
// 작업한다고 볼 수 있다.
// 2. cost per time 기준으로 정렬했을 때, paid painter가 소모한 시간 > free
// painter가 소모한 시간이 될 때까지 index를 조정한다.

// cost per time이 같은 것 끼리는 어떻게 정렬해야 하는가?
// 직관적인 생각: cost가 낮은 것 == time이 짧은 것이므로 이걸 paid에게 우선
// 배정해줌. 반례: [1,1,1,1,1,2,2,2,10] -> Fractional Knapsack이랑 똑같은 문제
// Knapsack에서는 그래서 DP를 사용했음.

// 근데 문제를 다시 읽어보니, 각 Painter가 쉬면 안된다는 말은 없음. 그러면 그냥
// 정렬해서 앞에 것들만 paid가 하면 되나? 그렇게 따지면, paid는 앞에서부터,
// free는 뒤에서부터 오면서, 각 segment마다 (paid 시간) <= (free 시간)을
// 만족하도록 쭉 진행한다?

// dp[i][w]: 0 ~ i번째 wall까지 총 w개의 벽을 칠했을 때 최소 cost -> dp[n -
// 1][n] dp[i][w] = min(dp[i - 1][w], cost[i] + dp[i - 1][max(0, w - (1 +
// time[i]))]) 처음 시작 -> 모두 0?
