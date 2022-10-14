// 2336. Smallest Number in Infinite Set
// https://leetcode.com/problems/smallest-number-in-infinite-set/

using namespace std;

#include <bitset>

class SmallestInfiniteSet {
public:
  bitset<1000> bs;
  int smallest;

  SmallestInfiniteSet() {
    bs.set();
    smallest = 1;
  }

  int popSmallest() {
    bs.set(smallest - 1, 0);
    int previousSmallest = smallest;

    while (smallest < bs.size() && bs.test(smallest - 1) == false) {
      smallest++;
    }

    return previousSmallest;
  }

  void addBack(int num) {
    bs.set(num - 1);
    smallest = min(smallest, num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
