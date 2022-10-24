#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define INDEX(i) (i - 1)

using namespace std;

int dp[1001][1001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string str1, str2;
  cin >> str1 >> str2;

  int len1 = str1.size(), len2 = str2.size();

  for (int i = 0; i <= len1; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= len2; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[INDEX(i)] == str2[INDEX(j)]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  vector<char> lcs;
  int i = len1, j = len2;
  while (i > 0 && j > 0) {
    if (str1[INDEX(i)] == str2[INDEX(j)]) {
      lcs.push_back(str1[INDEX(i)]);
      i--;
      j--;
    } else {
      if (dp[i - 1][j] >= dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }

  cout << dp[len1][len2] << '\n';
  for (vector<char>::reverse_iterator riter = lcs.rbegin(); riter != lcs.rend();
       riter++) {
    cout << *riter;
  }
  cout << '\n';
  return 0;
}
