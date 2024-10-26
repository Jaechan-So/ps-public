// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

using namespace std;

#include <string>

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int start = 0, end = 0, len = s.size(), answer = 0;

    if (len == 0) {
      return answer;
    }

    for (int i = 1; i < len; i++) {
      int loc;
      if ((loc = s.substr(start, end - start + 1).find(s[i])) != string::npos) {
        answer = max(answer, end - start + 1);
        start = start + loc + 1;
        end = i;
      } else {
        end = i;
      }
    }

    answer = max(answer, end - start + 1);

    return answer;
  }
};
