// 60. Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/description/

using namespace std;

#include <string>

class Solution {
public:
  string getPermutation(int n, int k) {
    if (n == 1) {
      return "1";
    }

    int factorials[10] = {
        0,
    };
    factorials[1] = 1;
    for (int i = 2; i <= 9; i++) {
      factorials[i] = factorials[i - 1] * i;
    }

    bool present[10];
    for (int i = 1; i <= n; i++) {
      present[i] = true;
    }

    int quotient = k - 1;
    string perm;

    while (perm.size() < n - 2) {
      int index = quotient / factorials[(n - perm.size() - 1)],
          remainder = quotient % factorials[(n - perm.size() - 1)];

      for (int i = 1; i <= n; i++) {
        if (present[i]) {
          if (index == 0) {
            present[i] = false;
            perm.push_back('0' + i);
            break;
          } else {
            index--;
          }
        }
      }

      quotient = remainder;
    }

    int smaller = -1, bigger = -1;
    for (int i = 1; i <= n; i++) {
      if (present[i]) {
        if (smaller == -1) {
          smaller = i;
        } else {
          bigger = i;
        }
      }
    }

    if (quotient == 0) {
      perm.push_back('0' + smaller);
      perm.push_back('0' + bigger);
    } else {
      perm.push_back('0' + bigger);
      perm.push_back('0' + smaller);
    }

    return perm;
  }
};
