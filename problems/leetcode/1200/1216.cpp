// 1216. Valid Palindrome III
// https://leetcode.com/problems/valid-palindrome-iii/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  int trackPalindrome(vector<vector<int>> &cache, string &s, int left,
                      int right) {
    if (cache[left][right] != -1) {
      return cache[left][right];
    }

    if (left == right) {
      cache[left][right] = 0;
      return cache[left][right];
    }

    if (left + 1 == right) {
      cache[left][right] = (s[left] == s[right] ? 0 : 1);
      return cache[left][right];
    }

    if (s[left] == s[right]) {
      cache[left][right] = trackPalindrome(cache, s, left + 1, right - 1);
      return cache[left][right];
    }

    cache[left][right] = min(trackPalindrome(cache, s, left + 1, right),
                             trackPalindrome(cache, s, left, right - 1)) +
                         1;
    return cache[left][right];
  }

  bool isValidPalindrome(string s, int k) {
    int n = s.size();
    vector<vector<int>> cache(n, vector<int>(n, -1));

    return trackPalindrome(cache, s, 0, s.size() - 1) <= k;
  }
};

// 양 끝에서 Palindrome을 만족하기 위해서 글자들을 뺀다고 생각하자.
// 1. 만약 양 끝 문자가 같으면, 그냥 뺀다. 일부러 빼지 않고, 제거해야 하는
// 경우가 있을 수 있는지 확인 필요. 일단 추측하기로는 제거해서 Palindrome이
// 나온다면 어차피 똑같은 거라서 그냥 제거하더라도 경우의 수를 탐색하는 데에
// 있어서 무방할 것 같다.
// 2. 만약 양 끝 문자가 다르면, 백트래킹으로 탐색하며 하나씩 제거해본다. 같아야
// 다음 스텝으로 넘어갈 수 있다.

// 위의 과정을 개선하여 DP를 적용하면 성능 측면에서 더 좋을 것 같다.
// 그러나 직접 해보니 Memory Limit Exceeded... O(n^3)이라 그런듯
// 일단 단순하게 left, right, r에 대해서 모두 캐싱을 했지만,
// 가령 r이 1일 때 성공했으면 2일 때는 들어와도 어차피 무조건 성공이니까 그런
// 식으로 저장해보는 쪽으로 가보자. 즉, 성공할 수 있는 최소 제거 횟수를
// 저장하자.

// 단순하게 횟수에 DP를 적용하는 쪽으로 가면 된다.
