#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n;
map<char, int> mapping;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    for (int i = 0; i < word.size(); i++) {
      char ch = word[word.size() - 1 - i];
      if (mapping.find(ch) != mapping.end()) {
        mapping[ch] += pow(10, i);
      } else {
        mapping[ch] = pow(10, i);
      }
    }
  }

  vector<int> pr;
  for (map<char, int>::iterator iter = mapping.begin(); iter != mapping.end();
       iter++) {
    pr.push_back(iter->second);
  }

  sort(pr.begin(), pr.end(), greater<int>());

  int sum = 0, current_number = 9;
  for (vector<int>::iterator iter = pr.begin(); iter != pr.end(); iter++) {
    sum += (*iter) * current_number;
    current_number--;
  }

  cout << sum << '\n';
  return 0;
}
