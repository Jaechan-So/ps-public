// 155. Min Stack
// https://leetcode.com/problems/min-stack/description/

#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

class MinStack {
public:
  vector<pii> valueAndMinimums;

  MinStack() {}

  void push(int val) {
    if (valueAndMinimums.size() == 0) {
      valueAndMinimums.push_back({val, val});
    } else {
      valueAndMinimums.push_back(
          {val, min(val, valueAndMinimums.back().second)});
    }
  }

  void pop() { valueAndMinimums.pop_back(); }

  int top() { return valueAndMinimums.back().first; }

  int getMin() { return valueAndMinimums.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
