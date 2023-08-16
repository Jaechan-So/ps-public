// 2405. Optimal Partition of String
// https://leetcode.com/problems/optimal-partition-of-string/description

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  const int ALPHABET_COUNT = 'z' - 'a' + 1;

  int partitionString(string s) {
    vector<bool> appeared(ALPHABET_COUNT, false);

    int partition = 0;
    for (char ch : s) {
      if (appeared[ch - 'a']) {
        partition++;
        for (int i = 0; i < ALPHABET_COUNT; i++) {
          appeared[i] = false;
        }
      }
      appeared[ch - 'a'] = true;
    }

    return partition + 1;
  }
};
