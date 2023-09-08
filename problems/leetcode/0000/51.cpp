// 51. N-Queens
// https://leetcode.com/problems/n-queens/description/

using namespace std;

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  vector<vector<string>> answer;
  vector<string> board;
  unordered_set<int> sum, diff, column;

  void track(int n) {
    int r = board.size();
    if (r == n) {
      answer.push_back(board);
      return;
    }

    for (int i = 0; i < n; i++) {
      int currentSum = r + i, currentDiff = r - i;
      if (sum.find(currentSum) == sum.end() &&
          diff.find(currentDiff) == diff.end() &&
          column.find(i) == column.end()) {
        string line;
        for (int j = 0; j < i; j++) {
          line.push_back('.');
        }
        line.push_back('Q');
        for (int j = 0; j < n - i - 1; j++) {
          line.push_back('.');
        }

        board.push_back(line);
        sum.insert(currentSum);
        diff.insert(currentDiff);
        column.insert(i);

        track(n);

        board.pop_back();
        sum.erase(currentSum);
        diff.erase(currentDiff);
        column.erase(i);
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    track(n);
    return answer;
  }
};

// 대각선의 특징
// 1. Positive Slope: 합친 값이 일정함.
// 2. Negative Slope: 차이가 일정함.
