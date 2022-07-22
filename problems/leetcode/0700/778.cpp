// 778. Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/

using namespace std;

#include <queue>
#include <utility>
#include <vector>

typedef pair<int, pair<int, int>> height_coordinate;

enum SourceType { NONE, SRC, DEST, TBD };

vector<pair<int, int>> directions({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

class Solution {
public:
  SourceType visited[50][50];
  int swimInWater(vector<vector<int>> &grid) {
    int answer = 0, n = grid.size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        visited[i][j] = NONE;
      }
    }

    priority_queue<height_coordinate, vector<height_coordinate>,
                   greater<height_coordinate>>
        pq;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        pq.push({grid[i][j], {i, j}});
      }
    }

    while (!pq.empty()) {
      height_coordinate hc = pq.top();
      pq.pop();

      int x = getX(hc), y = getY(hc);
      if (isConnectedSrcAndDestByVisiting(x, y, n)) {
        return getHeight(hc);
      }
    }

    return answer;
  }

  int getHeight(height_coordinate hc) { return hc.first; }

  int getX(height_coordinate hc) { return hc.second.first; }

  int getY(height_coordinate hc) { return hc.second.second; }

  int isSrc(int x, int y, int n) { return x == 0 && y == 0; }

  int isDest(int x, int y, int n) { return x == n - 1 && y == n - 1; }

  bool isConnectedSrcAndDestByVisiting(int x, int y, int n) {
    bool hasSrc = isSrc(x, y, n), hasDest = isDest(x, y, n);

    for (auto direction : directions) {
      int newX = x + direction.first, newY = y + direction.second;

      if (isValidPosition(newX, newY, n)) {
        hasSrc = hasSrc || visited[newX][newY] == SRC;
        hasDest = hasDest || visited[newX][newY] == DEST;
      }
    }

    SourceType visitedSourceType = hasSrc ? SRC : hasDest ? DEST : TBD;
    visited[x][y] = visitedSourceType;

    if (visitedSourceType == SRC || visitedSourceType == DEST) {
      changeSourceType(x, y, n, visitedSourceType);
    }

    bool isConnectedSrcAndDest = hasSrc && hasDest;
    return isConnectedSrcAndDest;
  }

  bool isValidPosition(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  void changeSourceType(int x, int y, int n, SourceType st) {
    for (auto direction : directions) {
      int newX = x + direction.first, newY = y + direction.second;

      if (isValidPosition(newX, newY, n) && visited[newX][newY] == TBD) {
        visited[newX][newY] = st;
        changeSourceType(newX, newY, n, st);
      }
    }
  }
};
