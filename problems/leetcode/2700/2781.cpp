// 2781. Length of the Longest Valid Substring
// https://leetcode.com/problems/length-of-the-longest-valid-substring/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestValidSubstring(string word, vector<string> &forbidden) {
    unordered_map<string, int> prefixToMinLength;

    for (int i = 0; i < forbidden.size(); i++) {
      string prefix;
      int len = forbidden[i].size();

      for (char ch : forbidden[i]) {
        prefix.push_back(ch);
        if (prefixToMinLength.find(prefix) == prefixToMinLength.end()) {
          prefixToMinLength[prefix] = len;
        } else {
          prefixToMinLength[prefix] = min(prefixToMinLength[prefix], len);
        }
      }
    }

    int start = 0, end = 0, maxLen = 0;
    string current;
    while (end < word.size()) {
      current.push_back(word[end]);

      bool isInvalid = false;
      for (int i = end; i > max(end - 10, start - 1); i--) {
        int len = end - i + 1;
        if (prefixToMinLength[word.substr(i, len)] == len) {
          // Invalid
          maxLen = max(maxLen, end - start);
          start = i + 1;
          end++;
          current = word.substr(start, end - start);
          isInvalid = true;
          break;
        }
      }

      if (!isInvalid) {
        end++;
      }
    }

    maxLen = max(maxLen, end - start);
    return maxLen;
  }
};

// Kadane 알고리즘처럼, word를 하나씩 늘려가면서 valid 한 지 확인한다.
// 만약 한 글자를 늘렸는데, 기존의 valid substring이 invalid 해진다면,
// 거기서부터 다시 시작해야 한다. 여전히 valid하다면, 추가하고 계속 진행한다.
// 시간 복잡도 조건을 만족하기 위해서는, 현재 substring과 forbidden을 적어도
// O(logn) 이하로 비교할 수 있어야 한다. 각 forbidden 문자에 대해서, 다음 문자에
// 대한 포인터를 들고 있으면서 비교하면 되지 않을까?

// 아호코라식 + Sliding Window? 그럼 이론상 O(N + sigma(M_i))로 해결 가능한데,
// 문제는 아호코라식을 모름

// 각 forbidden 문자열에 대해서, 조합 가능한 모든 prefix를 찾아낸다. (O(F * 10))
// 각 prefix가 포함된 최소의 문자열 길이를 저장해둔다.
// Sliding Window로 이동하면서, (이 때 문자열 자체의 길이를 저장하되, 내부적으로
// substring으로 고려하는 포인터는 따로 들고 있어야 함... 이 아니라 그냥
// max(start, end - 10)으로 처리하면 됨)
