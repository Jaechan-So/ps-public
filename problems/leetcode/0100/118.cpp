// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

using namespace std;

#include <vector>

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalTriangle;

    pascalTriangle.push_back(vector<int>({1}));
    for (int i = 2; i <= numRows; i++) {
      vector<int> currentRow;
      currentRow.push_back(1);
      for (int j = 0; j < i - 2; j++) {
        currentRow.push_back(pascalTriangle.back()[j] +
                             pascalTriangle.back()[j + 1]);
      }
      currentRow.push_back(1);
      pascalTriangle.push_back(currentRow);
    }

    return pascalTriangle;
  }
};
