// 729. My Calendar I
// https://leetcode.com/problems/my-calendar-i/

using namespace std;

#include <map>

class MyCalendar {
public:
  map<int, int> schedule;

  MyCalendar() {}

  bool book(int start, int end) {
    if (schedule.empty()) {
      schedule.insert({start, end});
      return true;
    }

    map<int, int>::iterator iter = schedule.lower_bound(start);
    if (iter == schedule.end()) {
      iter--;
      if (start < iter->second) {
        return false;
      }
      schedule.insert({start, end});
      return true;
    }
    if (iter == schedule.begin() && end <= iter->first) {
      schedule.insert({start, end});
      return true;
    }
    if (iter->first < end) {
      return false;
    }

    map<int, int>::iterator prevIter = prev(iter);
    if (start < prevIter->second) {
      return false;
    }

    schedule.insert({start, end});
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
