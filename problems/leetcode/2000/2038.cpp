// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

using namespace std;

#include <string>

class Solution {
public:
  bool winnerOfGame(string colors) {
    int n = colors.size(), countOfA = 0, countOfB = 0;

    char prev = colors[0];
    int current = 1;
    for (int i = 1; i < n; i++) {
      if (prev == colors[i]) {
        current++;
      } else {
        if (prev == 'A') {
          countOfA += max(current - 2, 0);
        } else {
          countOfB += max(current - 2, 0);
        }
        prev = colors[i];
        current = 1;
      }
    }
    if (prev == 'A') {
      countOfA += max(current - 2, 0);
    } else {
      countOfB += max(current - 2, 0);
    }

    return countOfA > countOfB;
  }
};

// 특정 문자의 묶음의 길이가 2 미만이 될 수 없다. (2가 되는 순간부터 제거
// 불가능) 따라서, 개수를 세서 A가 더 크면 Alice가 이기고 작거나 같으면 Bob이
// 이긴다.
