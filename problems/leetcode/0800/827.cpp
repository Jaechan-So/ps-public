// 827. Making A Large Island
// https://leetcode.com/problems/making-a-large-island/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  const int xDir[4] = {1, -1, 0, 0};
  const int yDir[4] = {0, 0, 1, -1};

  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> areas;

    // 1. Mark all islands with each area. Here we assign a island number.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          areas.push_back(0);
          markIsland(grid, areas, n, i, j, -areas.size());
        }
      }
    }

    int maxArea = areas.size() == 0 ? 0 : areas[0];
    for (int area : areas) {
      maxArea = max(maxArea, area);
    }

    // 2. If we find connecting zero with different island number, then record.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          maxArea = max(maxArea, getConnectedMaxArea(grid, areas, n, i, j));
        }
      }
    }

    return maxArea;
  }

  void markIsland(vector<vector<int>> &grid, vector<int> &areas, int n, int x,
                  int y, int islandNumber) {
    grid[x][y] = islandNumber;
    areas.back()++;

    for (int i = 0; i < 4; i++) {
      int newX = x + xDir[i], newY = y + yDir[i];

      if (isValidCoordinate(grid, n, newX, newY) && grid[newX][newY] == 1) {
        markIsland(grid, areas, n, newX, newY, islandNumber);
      }
    }
  }

  bool isValidCoordinate(vector<vector<int>> &grid, int n, int x, int y) {
    return (x >= 0) && (x < n) && (y >= 0) && (y < n);
  }

  int getConnectedMaxArea(vector<vector<int>> &grid, vector<int> &areas, int n,
                          int x, int y) {
    int area = 1;
    set<int> islandIndicies;

    for (int i = 0; i < 4; i++) {
      int newX = x + xDir[i], newY = y + yDir[i];

      if (isValidCoordinate(grid, n, newX, newY) && grid[newX][newY] != 0) {
        int islandIndex = -grid[newX][newY] - 1;
        islandIndicies.insert(islandIndex);
      }
    }

    for (int index : islandIndicies) {
      area += areas[index];
    }

    return area;
  }
};
