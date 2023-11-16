// 864. Shortest Path to Get All Keys
// https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

using namespace std;

#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  unordered_set<char> keys, locks;
  int m = 0, n = 0;

  bool isValidCoordinate(int i, int j) {
    return 0 <= i && i < m && 0 <= j && j < n;
  }

  bool isWall(vector<string> &grid, int i, int j) { return grid[i][j] == '#'; }

  bool isKey(vector<string> &grid, int i, int j) {
    return 'a' <= grid[i][j] && grid[i][j] <= 'z';
  }

  bool isLock(vector<string> &grid, int i, int j) {
    return 'A' <= grid[i][j] && grid[i][j] <= 'Z';
  }

  bool isStarting(vector<string> &grid, int i, int j) {
    return grid[i][j] == '@';
  }

  int addKeyToState(int state, char key) { return state | (1 << (key - 'a')); }

  bool isUnlockable(int state, char lock) {
    return (state & (1 << (lock - 'A'))) != 0;
  }

  int shortestPathAllKeys(vector<string> &grid) {
    m = grid.size(), n = grid[0].size();

    // 1. Gather the set of keys, locks and the starting point.
    int startI = 0, startJ = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isKey(grid, i, j)) {
          keys.insert(grid[i][j]);
        } else if (isLock(grid, i, j)) {
          locks.insert(grid[i][j]);
        } else if (isStarting(grid, i, j)) {
          startI = i;
          startJ = j;
        }
      }
    }
    int k = keys.size(), allKeyState = (1 << k) - 1;

    // 2. Construct BFS queue and visited map per key state.
    unordered_map<int, set<pair<int, int>>> visited;
    queue<vector<int>> q; // { i, j, key state, cumulative distance }
    q.push({startI, startJ, 0, 0});

    // 3. Do BFS with key state.
    while (!q.empty()) {
      int i = q.front()[0], j = q.front()[1], state = q.front()[2],
          dist = q.front()[3];
      q.pop();

      if (visited[state].find({i, j}) != visited[state].end()) {
        continue;
      }
      visited[state].insert({i, j});

      int nextState = state;
      if (isKey(grid, i, j)) {
        nextState = addKeyToState(nextState, grid[i][j]);
      }
      if (nextState == allKeyState) {
        return dist;
      }

      for (int k = 0; k < 4; k++) {
        int nextI = i + dx[k], nextJ = j + dy[k];

        if (!isValidCoordinate(nextI, nextJ) || isWall(grid, nextI, nextJ)) {
          continue;
        }

        if (isLock(grid, nextI, nextJ) &&
            !isUnlockable(nextState, grid[nextI][nextJ])) {
          continue;
        }

        q.push({nextI, nextJ, nextState, dist + 1});
      }
    }

    return -1;
  }
};

// 질문 리스트
// 1. Starting Point는 오직 1개인가? -> Yes
// 2. 애초에 불가능한 케이스(e.g. 벽에 둘러쌓인 곳에 열쇠가 있다던지)가 예제로
// 주어질 수 있는지? -> Yes라고 생각해야 할 듯함
// 3. k의 조건에 따라서 열쇠-자물쇠 쌍은 1개부터 6개까지로만 존재할 수 있는가?
// -> Yes
// 4. Key를 재사용하는 구조인가? 즉, 어떤 Key를 가지고 있으면 그에 대응되는
// 자물쇠를 이제부터 무조건 열 수 있다고 봐야 하는가? -> Yes

// 1. Brute Force
// 모든 Cell을 돌아다니며 모든 경우의 수를 추적한다. (BFS)
// 이 방법은 모든 열쇠를 얻을 수 없는 불가능한 경우를 걸러낼 수 없어, 무한루프에
// 빠질 수 있다.

// 2. Backtracking
// 열쇠를 얻는 순서를 배열하는 모든 경우의 수에 대해 (6! = 720) 고려한다.
// 각 경우에 대해서, (Starting) -> (Key 1) -> (Key 2) -> ... 순으로 진행하면서,
// 얻어야 하는 Key로부터 현재 사람의 위치쪽으로 이동하면서 최단 경로를 찾는다.
// 만약 불가능한 경우, 이 케이스를 버린다. 시간 복잡도 O(k! * k * m * n) <= 720
// * 6 * 30 * 30 == 4320 * 900 ~= 4320000 ~= 4 * 10^6

// [Solution] BFS with key states
// 하나의 Key를 얻으면 이미 지나온 Cell을 다시 방문할 수 있음을 이용해서 BFS로
// 최단거리를 구한다.
