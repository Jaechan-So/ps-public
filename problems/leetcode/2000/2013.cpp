// 2013. Detect Squares
// https://leetcode.com/problems/detect-squares/description/

using namespace std;

#include <map>
#include <vector>

#define abs(x) (((x) > 0) ? (x) : (-(x)))

class DetectSquares {
public:
  map<int, vector<int>> xToY, yToX;
  map<pair<int, int>, int> coordinateCounts;

  DetectSquares() {}

  void add(vector<int> point) {
    int x = point[0], y = point[1];

    xToY[x].push_back(y);
    yToX[y].push_back(x);
    coordinateCounts[{x, y}]++;
  }

  int count(vector<int> point) {
    int x = point[0], y = point[1], count = 0;

    for (int possibleX : yToX[y]) {
      for (int possibleY : xToY[x]) {
        int sideX = abs(possibleX - x), sideY = abs(possibleY - y);
        if (sideX != 0 && sideY != 0 && sideX == sideY) {
          count += coordinateCounts[{possibleX, possibleY}];
        }
      }
    }

    return count;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
