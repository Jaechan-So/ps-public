// 6288. Find Consecutive Integers from a Data Stream
// https://leetcode.com/contest/biweekly-contest-95/problems/find-consecutive-integers-from-a-data-stream/
// Result: Accepted

class DataStream {
private:
  int timestamp = 0, lastNotMatchedTimestamp = 0, _value, _k;

public:
  DataStream(int value, int k) {
    _value = value;
    _k = k;
  }

  bool consec(int num) {
    timestamp++;
    if (_value != num) {
      lastNotMatchedTimestamp = timestamp;
    }
    return (timestamp - lastNotMatchedTimestamp) >= _k;
  }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
