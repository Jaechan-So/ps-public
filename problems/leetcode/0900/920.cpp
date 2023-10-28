// 920. Number of Music Playlists
// https://leetcode.com/problems/number-of-music-playlists/description/

using namespace std;

#include <vector>

class Solution {
public:
  const int mod = 1e9 + 7;

  int numMusicPlaylists(int n, int goal, int k) {
    vector<vector<long long>> playlists(goal + 1, vector<long long>(n + 1, 0));
    playlists[0][0] = 1;

    for (int i = 1; i <= goal; i++) {
      for (int j = 1; j <= min(i, n); j++) {
        playlists[i][j] += ((playlists[i - 1][j - 1] * (n - j + 1)) % mod);

        if (j > k) {
          playlists[i][j] += ((playlists[i - 1][j] * (j - k)) % mod);
        }
      }
    }

    return playlists[goal][n] % mod;
  }
};
