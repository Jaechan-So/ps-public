// 30. Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  unordered_map<string, int> wordCount;
  vector<int> validIndicies;

  vector<int> findSubstring(string s, vector<string> &words) {
    int n = s.size(), p = words.size(), q = words[0].size();

    for (string &word : words) {
      wordCount[word]++;
    }

    for (int remainder = 0; remainder < q; remainder++) {
      unordered_map<string, int> currentWordCount;

      for (int batch = 0; batch < p; batch++) {
        int startIndex = remainder + (batch * q), endIndex = startIndex + q;
        if (endIndex >= n + 1) {
          break;
        }

        string currentWord = s.substr(startIndex, q);
        if (wordCount.find(currentWord) != wordCount.end()) {
          currentWordCount[currentWord]++;
        }
      }

      int batch = 0;
      while (true) {
        bool satisfied = true;

        for (unordered_map<string, int>::iterator iter = wordCount.begin();
             iter != wordCount.end(); iter++) {
          if (currentWordCount[iter->first] != iter->second) {
            satisfied = false;
            break;
          }
        }

        int startIndex = remainder + (batch * q);
        if (satisfied) {
          validIndicies.push_back(startIndex);
        }

        int newStartIndex = startIndex + (p * q);
        if (newStartIndex + q >= n + 1) {
          break;
        }

        if (wordCount.find(s.substr(startIndex, q)) != wordCount.end()) {
          currentWordCount[s.substr(startIndex, q)]--;
        }
        if (wordCount.find(s.substr(newStartIndex, q)) != wordCount.end()) {
          currentWordCount[s.substr(newStartIndex, q)]++;
        }

        batch++;
      }
    }

    return validIndicies;
  }
};

// 1. Naive Solution
// Sliding Window + 모든 문자 비교
// s.size() = n, words.size() = p, words[i].size() = q;
// O(n * (p!) * pq)

// 2.
// words에 들어 있는 단어에 대한 Trie가 있다면 단어 체크는 O(q) ->
// unordered_map으로 교체해서 구현 O(nq) -> 각 시작 위치에서 해당하는 단어가
// 있는지 확인 가능 O(q * ((n / q) - p)), (k - 1 + p) * q <= n -> 각 시작 위치
// 기준으로, 주어진 Permutation이 나오나 확인 가능, Sliding Window의 풀이 방법을
// 적용해볼 수 있음 총 O(nq)
