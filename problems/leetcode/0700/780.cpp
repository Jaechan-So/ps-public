// 780. Reaching Points
// https://leetcode.com/problems/reaching-points/description/

using namespace std;

#include <utility>

class Solution {
public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (sx <= tx && sy <= ty) {
      if (sx == tx && sy == ty) {
        return true;
      }

      if (tx < ty) {
        swap(sx, sy);
        swap(tx, ty);
      }

      int q = tx / ty, r = tx % ty;
      if (sy == ty && (sx - r) % ty == 0 && r <= sx && sx <= tx) {
        return true;
      }

      tx = r;
    }

    return false;
  }
};

// 일반성을 잃지 않고 (x, y) 점에 대해 x > y라고 하면, (같은 경우는 불가능) 이
// 전의 점은 (x - y, y)여야만 한다. 따라서 이를 하나씩 확인하면 10^9 만큼
// 확인해야 해서 TLE가 날 것.

// m1 * sx + n1 * sy = tx, m2 * sx + n2 * sy = ty를 만족하는 m1, m2, n1, n2가
// 존재하는지 찾아야 한다. (m, n >= 0) 존재하지 않으면 애초에 불가능. 존재한다고
// 가정했을 때

// 일반성을 잃지 않고 (x, y) 점에 대해 x > y라고 하면, (같은 경우는 불가능) 이
// 전의 점은 (x - y, y)여야만 한다. x = q * y + r이라고 했을 때, 한 번에 (r,
// y)로 넘어갈 수 있다. 이 때, sy == y이면 (sx, sy)가 중간에 있을 수도 있기
// 때문에, (sx - r) % y == 0이고, (r <= sx && sx <= x)면 그 사이에 걸렸다는 말이
// 된다.
