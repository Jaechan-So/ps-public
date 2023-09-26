// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/description/

using namespace std;

#include <queue>
#include <vector>

class MedianFinder {
public:
  priority_queue<int, vector<int>, less<int>> smaller;
  priority_queue<int, vector<int>, greater<int>> bigger;
  int middle = 0;
  bool isInitialized = false;

  MedianFinder() {}

  void addNum(int num) {
    if (!isInitialized) {
      middle = num;
      isInitialized = true;
      return;
    }

    if (smaller.size() == bigger.size()) {
      if (middle <= num) {
        bigger.push(num);
      } else {
        smaller.push(num);
        bigger.push(middle);
        middle = smaller.top();
        smaller.pop();
      }
    } else {
      if (middle <= num) {
        bigger.push(num);
        smaller.push(middle);
        middle = bigger.top();
        bigger.pop();
      } else {
        smaller.push(num);
      }
    }
  }

  double findMedian() {
    if (smaller.size() == bigger.size()) {
      return (double)middle;
    }
    return ((double)middle + (double)bigger.top()) / 2;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Priority Queue 2개를 유지한다.
// 현재 median을 기준으로, 작은 쪽과 큰 쪽을 가진 큐들이다.
// 새로운 원소가 들어오면, 맞는 쪽으로 집어넣은 뒤
// 바뀐 사이즈에 맞춰 큐를 재조정한다.
// 편의를 위해서, 작은 쪽의 큐가 더 작은 구조로 구현한다.

// Follow up 1. [0, 100]의 범위의 수만 들어온다면, Counting Sort를 이용해서
// 최적화할 수 있다. addNum은 단순히 입력값의 count와 전체 길이 값을 증가시키는
// 쪽으로 한다. (O(1)) findMedian은 현재 길이를 알고 있으므로, 0부터 100까지의
// count를 순회하며 적절한 값을 찾는다. (O(1))

// Follow up 2. 99%의 숫자만 [0, 100]의 범위의 수만 들어온다면, 우선 초반에는
// Priority Queue 방식으로 사용하다가, 모수가 충분히 확보되어 Median 값 자체가
// [0, 100] 범위 안으로 들어오면 그 때부터는 바깥 값을 버리고 안 쪽에서만
// counting해서 사용한다. 이 때 전체 입력 개수는 버리면 안 된다.
