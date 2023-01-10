// 990. Satisfiability of Equality Equations
// https://leetcode.com/problems/satisfiability-of-equality-equations/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int parents[27] = {
      0,
  };

  bool equationsPossible(vector<string> &equations) {
    for (int i = 0; i < equations.size(); i++) {
      // First, check only equality.
      if (equations[i][1] == '!') {
        continue;
      }

      int n1 = charToIndex(equations[i][0]), n2 = charToIndex(equations[i][3]);
      int p1 = findParent(n1), p2 = findParent(n2);

      if (p1 == 0 && p2 == 0) {
        parents[n1] = n1;
        parents[n2] = n1;
        continue;
      }

      if (p1 == 0 && p2 != 0) {
        parents[n1] = p2;
        continue;
      }

      if (p1 != 0 && p2 == 0) {
        parents[n2] = p1;
        continue;
      }

      while (n2 != parents[n2]) {
        int prevParent = parents[n2];
        parents[n2] = p1;
        n2 = prevParent;
      }
      parents[n2] = p1;
    }

    for (int i = 0; i < equations.size(); i++) {
      // Then, check only inequality.
      if (equations[i][1] == '=') {
        continue;
      }

      int n1 = charToIndex(equations[i][0]), n2 = charToIndex(equations[i][3]);
      int p1 = findParent(n1), p2 = findParent(n2);

      if (n1 == n2) {
        return false;
      }

      if (p1 != 0 && p2 != 0 && p1 == p2) {
        return false;
      }
    }

    return true;
  }

  int charToIndex(char ch) { return ch - 'a' + 1; }

  int findParent(int n) {
    while (n != parents[n]) {
      n = parents[n];
    }
    return n;
  }
};
