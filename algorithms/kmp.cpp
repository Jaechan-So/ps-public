#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Kmp {
private:
  void failure_function_base_case(vector<int> &failures) {
    failures.push_back(1);
    failures.push_back(1);
  }

  vector<int> failure_function(string &s) {
    int len = s.size();
    vector<int> failures;

    failure_function_base_case(failures);

    int current_success_index = 0;
    for (int i = 2; i <= len; i++) {
      int index = i - 1;

      while (current_success_index >= 0 &&
             s[current_success_index] != s[index]) {
        current_success_index--;
      }

      int failure =
          current_success_index < 0 ? 1 : index - current_success_index;
      failures.push_back(failure);

      current_success_index++;
    }

    return failures;
  }

public:
  vector<int> kmp(string &haystack, string &needle) {
    vector<int> result;
    vector<int> failures = failure_function(needle);
    int haystack_len = haystack.size();
    int needle_len = needle.size();

    int current_haystack_index = 0;
    int current_needle_gap = 0;

    while (current_haystack_index < haystack_len - needle_len + 1) {
      if (haystack[current_haystack_index + current_needle_gap] ==
          needle[current_needle_gap]) {
        current_needle_gap++;
        if (current_needle_gap == needle_len) {
          result.push_back(current_haystack_index);
          current_haystack_index += needle_len;
        }
      } else {
        current_haystack_index += failures[current_needle_gap];
        current_needle_gap = 0;
      }
    }

    return result;
  }
};

int main() {
  string haystack("aababaabab");
  string needle("aabab");

  Kmp kmp = Kmp();
  vector<int> answer = kmp.kmp(haystack, needle);

  for (auto i : answer) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}
