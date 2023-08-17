// 2268. Minimum Number of Keypresses
// https://leetcode.com/problems/minimum-number-of-keypresses/description

using namespace std;

#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  const int ALPHABET_COUNT = 'z' - 'a' + 1;
  int minimumKeypresses(string s) {
    vector<int> charToCount(ALPHABET_COUNT, 0);
    for (char ch : s) {
      charToCount[ch - 'a']++;
    }
    sort(charToCount.begin(), charToCount.end(), greater<int>());

    int count = 0, keypress = 0;
    for (int i = 0; i < ALPHABET_COUNT; i++) {
      if (charToCount[i] == 0) {
        break;
      }
      keypress += ((count / 9) + 1) * charToCount[i];
      count++;
    }

    return keypress;
  }
};
