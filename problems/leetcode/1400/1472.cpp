// 1472. Design Browser History
// https://leetcode.com/problems/design-browser-history/

using namespace std;

#include <string>
#include <vector>

class BrowserHistory {
public:
  vector<string> pages;
  int cursor;

  BrowserHistory(string homepage) {
    pages.push_back(homepage);
    cursor = 0;
  }

  void visit(string url) {
    pages.erase(pages.begin() + cursor + 1, pages.end());
    pages.push_back(url);
    cursor = pages.size() - 1;
  }

  string back(int steps) {
    cursor = (cursor < steps ? 0 : cursor - steps);
    return pages[cursor];
  }

  string forward(int steps) {
    cursor =
        (cursor + steps < pages.size() ? cursor + steps : pages.size() - 1);
    return pages[cursor];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
