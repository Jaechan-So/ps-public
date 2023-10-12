// 1062. Longest Repeating Substring
// https://leetcode.com/problems/longest-repeating-substring/description/

using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  int longestRepeatingSubstring(string s) {
    int n = s.size();
    unordered_map<string, int> words;

    for (int i = 0; i < n; i++) {
      string current;

      for (int j = i; j < n; j++) {
        current.push_back(s[j]);
        words[current]++;
      }
    }

    int maxLength = 0;
    for (unordered_map<string, int>::iterator iter = words.begin();
         iter != words.end(); iter++) {
      if (iter->second > 1) {
        maxLength = max(maxLength, (int)iter->first.size());
      }
    }
    return maxLength;
  }
};

// s[0..k - 1]에 s[k]가 추가되는 시나리오를 생각해보면, substring k개가
// 추가된다. 이전까지 추가되어 있는 substring을 모두 저장하고 있다면 모두 세면
// 된다.
