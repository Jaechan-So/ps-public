// 1884. Egg Drop With 2 Eggs and N Floors
// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

class Solution {
public:
  int twoEggDrop(int n) {
    int start = 1, end = n;

    while (start < end) {
      int mid = (start + end + 1) / 2;
      if (mid * (mid + 1) > 2 * n) {
        end = mid - 1;
      } else {
        start = mid;
      }
    }

    return start * (start + 1) == 2 * n ? start : start + 1;
  }
};

// 크기 k인 단위로 아래에서부터 쪼갠다. (k가 꼭 n의 약수일 필요는 없음.) 이
// 시나리오에서 가장 오래 걸리는 케이스에 대한 가지수는...
// 1. n / k 번째 (즉, 마지막으로 나누어 떨어지는 층 수)에서 깨져서, 그 단위
// 안에서 1개씩 시도해야 하는 경우. 이 때 필요한 횟수는 (n / k) + (k - 1)
// 2. n / k 번째에서 안 깨졌을 경우? n - (n / k) * k 만큼의 경우의 수가 있고,
// 달걀은 2개가 남아 있는 상황임. 그럼 이건 마찬가지로 twoEggDrop(n - (n / k) *
// k)로 구하면 되나..? 이 전략을 사용할 경우, 최적의 크기 k를 구해야 한다.
// 가능한 k의 범위를 알 수 있나?
// 일단, (n / 2)를 넘어갈 이유는 없음. 그 이상으로 넘어가는 경우, 최악의 경우
// 걸리는 횟수가 n / 2보다 커지기 때문에..

// Example에 있는 전략
// 층까지 오는 횟수 + 단위 안에서 실패하는 횟수를 일정하게 맞추기 위해서, 한
// 단위 위로 올라갈 때마다 단위의 크기를 하나 줄이는 방법. 그래서 꼭대기부터
// 시작해서 아래로 내려와야 함. k(k + 1) / 2 <= n 을 만족하는 가장 큰 k를
// 구하면, 등호일 경우 k, 아닐 경우 k + 1이 횟수. 왜냐하면, 조건을 만족하는 가장
// 아래 층 단위까지 오는 횟수가 등호이면 0이고 아니면 1이고, 단위 안에서 총
// 횟수가 k이기 때문.
