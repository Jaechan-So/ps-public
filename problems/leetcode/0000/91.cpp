// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/description/

#include <map>
#include <string>

using namespace std;

class Solution {
public:
  bool isPossibleTwoDigitEncoding(char &ch1, char &ch2) {
    return (ch1 == '1') || (ch1 == '2' && ('0' <= ch2 && ch2 <= '6'));
  }

  int countDecodeWay(string &s, map<int, int> &indexToCount, int index) {
    if (indexToCount.find(index) != indexToCount.end()) {
      return indexToCount[index];
    }

    if (index >= s.size()) {
      return 1;
    }

    if (s[index] == '0') {
      return 0;
    }

    // Except '0', the single digit always has a decode way i.e. 'A' to 'I'.
    int count = countDecodeWay(s, indexToCount, index + 1);

    if (index + 1 < s.size() &&
        isPossibleTwoDigitEncoding(s[index], s[index + 1])) {
      count += countDecodeWay(s, indexToCount, index + 2);
    }

    indexToCount[index] = count;
    return count;
  }

  int numDecodings(string s) {
    map<int, int> indexToCount;
    return countDecodeWay(s, indexToCount, 0);
  }
};
