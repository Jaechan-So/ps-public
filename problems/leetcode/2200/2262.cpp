// 2262. Total Appeal of A String
// https://leetcode.com/problems/total-appeal-of-a-string/description/

using namespace std;

#include <map>
#include <string>

class Solution {
public:
  long long appealSum(string s) {
    int n = s.size();

    unordered_map<char, int> lastIndicies;
    for (char ch = 'a'; ch <= 'z'; ch++) {
      lastIndicies[ch] = -1;
    }

    long long sum = 0, prevLineSum = 0;
    for (int i = 0; i < s.size(); i++) {
      prevLineSum += (i - lastIndicies[s[i]]);
      sum += prevLineSum;
      lastIndicies[s[i]] = i;
    }

    return sum;
  }
};

// 마지막으로 해당 원소가 등장한 위치를 관리?
