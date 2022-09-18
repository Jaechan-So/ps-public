// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int sCount[26] =
      {
          0,
  },
      pCount[26] = {
          0,
  };

  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return vector<int>();
    }

    vector<int> answer;

    for (int i = 0; i < p.size(); i++) {
      pCount[convertAlphaToIndex(p[i])]++;
    }

    for (int i = 0; i < p.size(); i++) {
      sCount[convertAlphaToIndex(s[i])]++;
    }

    if (isAnagram()) {
      answer.push_back(0);
    }

    for (int i = 1; i < s.size() - p.size() + 1; i++) {
      sCount[convertAlphaToIndex(s[i - 1])]--;
      sCount[convertAlphaToIndex(s[i + p.size() - 1])]++;

      if (isAnagram()) {
        answer.push_back(i);
      }
    }

    return answer;
  }

  int convertAlphaToIndex(char ch) { return ch - 'a'; }

  bool isAnagram() {
    for (int i = 0; i < 26; i++) {
      if (sCount[i] != pCount[i]) {
        return false;
      }
    }

    return true;
  }
};
