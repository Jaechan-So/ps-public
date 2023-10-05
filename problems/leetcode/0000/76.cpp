// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/description/

using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
  string minWindow(string s, string t) {
    int m = s.size(), n = t.size();

    unordered_map<char, int> tCount;
    for (char ch : t) {
      tCount[ch]++;
    }

    unordered_map<char, int> sCount;
    int end = 0;
    while (end < m) {
      sCount[s[end++]]++;

      bool enough = true;
      for (unordered_map<char, int>::iterator iter = tCount.begin();
           iter != tCount.end(); iter++) {
        if (sCount[iter->first] < iter->second) {
          enough = false;
        }
      }
      if (enough) {
        end--;
        break;
      }
    }
    if (end == m) {
      return "";
    }

    int start = 0;
    while (start < end) {
      if (sCount[s[start]] - 1 >= tCount[s[start]]) {
        sCount[s[start++]]--;
      } else {
        break;
      }
    }

    int minLen = end - start + 1, startPos = start, endPos = end;
    while (end < m) {
      while (start < end) {
        if (sCount[s[start]] - 1 >= tCount[s[start]]) {
          sCount[s[start++]]--;
        } else {
          break;
        }
      }
      if (end - start + 1 < minLen) {
        minLen = end - start + 1;
        startPos = start;
        endPos = end;
      }
      end++;
      if (end < m) {
        sCount[s[end]]++;
      }
    }

    return s.substr(startPos, minLen);
  }
};

// 1. t에 있는 각 문자별로 개수를 세서, 일단 최소한 모두 등장하는 첫 위치를
// 찾는다. 이 때, 각 문자가 첫 번째로 등장하는 위치도 저장해둔다. 여기서 그런
// 위치가 없으면 빈 문자열을 리턴한다.
// 2. 해당 위치부터, 새로운 문자가 나오면 그 문자의 첫 위치를 갱신한다. 현재
// 위치와 현재까지 등장한 모든 문자의 위치들의 최솟값의 차이를 구하면 minimum
// window substring이 된다. 길이값을 확인하고, 최소라면 위치를 저장한다.

// 1. 단순하게 Sliding Window로 한다.
