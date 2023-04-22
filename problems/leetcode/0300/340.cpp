// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

using namespace std;

#include <map>
#include <string>

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0) {
      return 0;
    }

    int n = s.size(), distinctCounts = 0;
    map<char, int> counts;
    auto updateCount = [&](char ch) {
      if (counts[ch]++ == 0) {
        distinctCounts++;
      }
    };
    auto deleteCount = [&](char ch) {
      if (--counts[ch] == 0) {
        distinctCounts--;
      }
    };

    int right = 0;
    while (right < n) {
      updateCount(s[right++]);
      if (distinctCounts == k && counts[s[right]] == 0) {
        break;
      }
    }

    int left = 0, len = right - left;
    auto updateLen = [&]() { len = max(len, right - left); };
    while (right < n) {
      deleteCount(s[left++]);
      while (right < n && (distinctCounts < k ||
                           (distinctCounts == k && counts[s[right]] != 0))) {
        updateCount(s[right++]);
      }
      updateLen();
    }

    return len;
  }
};
