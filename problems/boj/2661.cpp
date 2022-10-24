#include <iostream>
#include <string>

using namespace std;

int n;
string answer;

bool promising(string &numbers) {
  int len = numbers.size();
  int index = 1;
  while (2 * index <= len) {
    if (numbers.substr(len - (2 * index), index) ==
        numbers.substr(len - index, index)) {
      return false;
    }
    index++;
  }
  return true;
}

void bt(string &numbers) {
  for (int i = 1; i <= 3; i++) {
    numbers.push_back(i + '0');
    if (answer.size() == 0 && promising(numbers)) {
      int len = numbers.size();
      if (len < n) {
        bt(numbers);
      } else if (len == n) {
        for (int i = 0; i < len; i++) {
          answer.push_back(numbers[i]);
        }
      }
    }
    numbers.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  answer = "";
  cin >> n;

  string numbers;
  bt(numbers);

  cout << answer << '\n';
  return 0;
}
