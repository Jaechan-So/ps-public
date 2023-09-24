// 2864. Maximum Odd Binary Number
// https://leetcode.com/contest/weekly-contest-364/problems/maximum-odd-binary-number/
// Result: Accepted

using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    unordered_map<char, int> count;
    for (char ch : s) {
      count[ch]++;
    }

    string answer;
    for (int i = 0; i < count['1'] - 1; i++) {
      answer.push_back('1');
    }
    for (int i = 0; i < count['0']; i++) {
      answer.push_back('0');
    }
    answer.push_back('1');

    return answer;
  }
};
