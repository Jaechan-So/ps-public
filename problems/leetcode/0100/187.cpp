// 187. Repeated DNA Sequences
// https://leetcode.com/problems/repeated-dna-sequences/

using namespace std;

#include <map>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
  int EARLY_NUM_ERASER = ~(3 << (2 * 9));
  vector<string> findRepeatedDnaSequences(string s) {
    set<string> answerSet;

    if (s.size() < 10) {
      return vector<string>();
    }

    map<int, bool> sequenceNumRecord;

    int sequenceNum = 0;
    for (int i = 0; i < 10; i++) {
      sequenceNum = sequenceNum << 2;
      sequenceNum += convertNucleotideToDigit(s[i]);
    }
    sequenceNumRecord.insert({sequenceNum, false});

    for (int i = 1; i <= s.size() - 10; i++) {
      sequenceNum = eraseEarlyNumAndShift(sequenceNum) +
                    convertNucleotideToDigit(s[i + 9]);
      if (sequenceNumRecord.find(sequenceNum) != sequenceNumRecord.end() &&
          sequenceNumRecord[sequenceNum] == false) {
        string repeatedDnaSequence = s.substr(i, 10);
        answerSet.insert(repeatedDnaSequence);
        sequenceNumRecord[sequenceNum] = true;
      } else {
        sequenceNumRecord.insert({sequenceNum, false});
      }
    }

    return vector<string>(answerSet.begin(), answerSet.end());
  }

  int convertNucleotideToDigit(char ch) {
    return ch == 'A' ? 0 : ch == 'C' ? 1 : ch == 'G' ? 2 : 3;
  }

  int eraseEarlyNumAndShift(int n) { return (n & EARLY_NUM_ERASER) << 2; }
};
