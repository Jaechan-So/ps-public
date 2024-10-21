// 895. Maximum Frequency Stack
// https://leetcode.com/problems/maximum-frequency-stack/description/

using namespace std;

#include <queue>
#include <unordered_map>
#include <vector>

class FreqStack {
public:
  int timestamp = 0;
  priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> pq;
  unordered_map<int, int> freq;

  FreqStack() {}

  void push(int val) {
    timestamp++;
    freq[val]++;
    pq.push({freq[val], timestamp, val});
  }

  int pop() {
    int val = pq.top()[2];
    pq.pop();
    freq[val]--;
    return val;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

// 1. Priority Queue 안에 (개수, timestamp) pair를 저장한다. 동시에 map 안에
// (값, timestamp의 vector)를 저장한다.
// 2. pop을 하면, Priority Queue를 클렌징(*)하고 가장 위의 원소를 반환한다.
