// 1138. Alphabet Board Path
// https://leetcode.com/problems/alphabet-board-path/

using namespace std;

#include <string>

class Solution {
public:
  string alphabetBoardPath(string target) {
    string path;
    char currentAlphabet = 'a', targetAlphabet;

    for (auto ch : target) {
      targetAlphabet = ch;

      int currentIndex = charToIndex(currentAlphabet),
          targetIndex = charToIndex(targetAlphabet);

      if (targetAlphabet == 'z') {
        moveHorizontal(path, currentIndex, targetIndex);
        moveVertical(path, currentIndex, targetIndex);
      } else if (currentAlphabet == 'z') {
        moveVertical(path, currentIndex, targetIndex);
        moveHorizontal(path, currentIndex, targetIndex);
      } else {
        moveVertical(path, currentIndex, targetIndex);
        moveHorizontal(path, currentIndex, targetIndex);
      }

      path.push_back('!');

      currentAlphabet = ch;
    }

    return path;
  }

  int charToIndex(char ch) { return ch - 'a'; }

  void moveVertical(string &path, int currentIndex, int targetIndex) {
    int currentQuotient = currentIndex / 5, targetQuotient = targetIndex / 5;
    int quotientDifference = targetQuotient - currentQuotient;

    for (int i = 0; i < abs(quotientDifference); i++) {
      path.push_back(quotientDifference > 0 ? 'D' : 'U');
    }
  }

  void moveHorizontal(string &path, int currentIndex, int targetIndex) {
    int currentRemainder = currentIndex % 5, targetRemainder = targetIndex % 5;
    int remainderDifference = targetRemainder - currentRemainder;

    for (int i = 0; i < abs(remainderDifference); i++) {
      path.push_back(remainderDifference > 0 ? 'R' : 'L');
    }
  }
};
