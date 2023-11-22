// 880. Decoded String at Index
// https://leetcode.com/problems/decoded-string-at-index/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int n = 0;
  long long len = 0;
  vector<string> tokens;

  bool isAlpha(char ch) { return 'a' <= ch && ch <= 'z'; }

  void parseTokens(string &s) {
    string token;

    for (char ch : s) {
      if (isAlpha(ch)) {
        token.push_back(ch);
        len++;
      } else {
        if (!token.empty()) {
          tokens.push_back(token);
          token.clear();
        }
        string newToken(1, ch);
        tokens.push_back(newToken);
        len *= (ch - '0');
      }
    }
    if (!token.empty()) {
      tokens.push_back(token);
    }
  }

  string decodeAtIndex(string s, int k) {
    n = s.size();
    parseTokens(s);

    long long offset = k - 1;
    for (int i = tokens.size() - 1; i >= 0; i--) {
      bool isScaleToken = !isAlpha(tokens[i][0]);
      if (isScaleToken) {
        int scale = tokens[i][0] - '0';
        long long segment = len / scale;
        offset %= segment;
        len = segment;
      } else {
        int tokenLen = tokens[i].size();
        long long prev = len - tokenLen;
        if (prev <= offset && offset < len) {
          string decoded(1, tokens[i][offset - prev]);
          return decoded;
        } else {
          len -= tokenLen;
        }
      }
    }

    return "";
  }
};

// 1. Naive
// 실제로 string을 만든 뒤 (k - 1)번째 인덱스에 접근.

// 2. 나머지 계산(?)
// 끝에 있는 수 기준으로 단어가 반복될 것이므로, k % (그 앞 단어 길이)로
// 계산하면 됨. 단어가 나오면 단어의 범위 안에 있는지 확인, 있으면 인덱스로
// 접근해서 반환. 숫자가 나오면 그 앞 단어 길이로 나눈 나머지로 k를 변환.
// 따라서, 필요한 건 string을 파싱했을 때 현재 토큰까지의 길이를 알아야 함.
// 각 토큰의 첫 번째 인덱스만 따로 저장해두기.
