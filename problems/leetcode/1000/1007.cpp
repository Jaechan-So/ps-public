// 1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

using namespace std;

#include <vector>

class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    int count = tops.size();

    // Indicates whether 1 to 6 appears all of seats.
    // Here the zero index does not have meaning.
    bool isDuplicateValue[7] = {true, true, true, true, true, true, true};

    // Observe what values are on current domino, and check whether appears all
    // of seats.
    for (int i = 0; i < count; i++) {
      int topValue = tops[i], bottomValue = bottoms[i];

      for (int j = 1; j <= 6; j++) {
        isDuplicateValue[j] =
            isDuplicateValue[j] && (j == topValue || j == bottomValue);
      }
    }

    // Find duplicate value. There can be maximum two kinds of value.
    int duplicateValueFirst = -1, duplicateValueSecond = -1;
    for (int i = 1; i <= 6; i++) {
      if (isDuplicateValue[i]) {
        if (duplicateValueFirst < 0) {
          duplicateValueFirst = i;
        } else {
          duplicateValueSecond = i;
        }
      }
    }

    // If there is no duplicate value, we cannot make single row with same
    // value.
    if (duplicateValueFirst < 0) {
      return -1;
    }

    int answer = INT_MAX;

    // Check top row and bottom row with the count that we have to make a single
    // row with first duplicate value.
    int topCountFirstTop = 0, topCountFirstBottom = 0;
    for (int i = 0; i < count; i++) {
      topCountFirstTop +=
          (tops[i] == duplicateValueFirst && bottoms[i] != duplicateValueFirst
               ? 1
               : 0);
      topCountFirstBottom +=
          (bottoms[i] == duplicateValueFirst && tops[i] != duplicateValueFirst
               ? 1
               : 0);
    }
    answer = min(topCountFirstTop, topCountFirstBottom);

    // Ditto. Do only when the second duplicate value exists.
    if (duplicateValueSecond > 0) {
      int topCountSecondTop = 0, topCountSecondBottom = 0;
      for (int i = 0; i < count; i++) {
        topCountSecondTop += (tops[i] == duplicateValueSecond &&
                                      bottoms[i] != duplicateValueSecond
                                  ? 1
                                  : 0);
        topCountSecondBottom += (bottoms[i] == duplicateValueSecond &&
                                         tops[i] != duplicateValueSecond
                                     ? 1
                                     : 0);
      }
      answer = min(topCountSecondTop, topCountSecondBottom);
    }

    return answer;
  }
};
