// 1601. Maximum Number of Achievable Transfer Requests
// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int total, mid, maxRequests = 0;
  map<vector<int>, int> rightStates;

  vector<int> inverse(vector<int> &v) {
    vector<int> inversed;

    for (int n : v) {
      inversed.push_back(-n);
    }

    return inversed;
  }

  void constructRightStatesInner(vector<vector<int>> &requests, int index,
                                 vector<int> &state, int accepted) {
    if (index == requests.size()) {
      rightStates[state] = max(rightStates[state], accepted);
      return;
    }

    constructRightStatesInner(requests, index + 1, state, accepted);

    int from = requests[index][0], to = requests[index][1];
    state[from]--;
    state[to]++;
    constructRightStatesInner(requests, index + 1, state, accepted + 1);
    state[from]++;
    state[to]--;
  }

  void constructRightStates(vector<vector<int>> &requests) {
    vector<int> state(total, 0);
    constructRightStatesInner(requests, mid, state, 0);
  }

  void traverseLeftStatesInner(vector<vector<int>> &requests, int index,
                               vector<int> &state, int accepted) {
    if (index == mid) {
      vector<int> inversed = inverse(state);
      if (rightStates.find(inversed) != rightStates.end()) {
        maxRequests = max(maxRequests, accepted + rightStates[inversed]);
      }
      return;
    }

    traverseLeftStatesInner(requests, index + 1, state, accepted);

    int from = requests[index][0], to = requests[index][1];
    state[from]--;
    state[to]++;
    traverseLeftStatesInner(requests, index + 1, state, accepted + 1);
    state[from]++;
    state[to]--;
  }

  void traverseLeftStates(vector<vector<int>> &requests) {
    vector<int> state(total, 0);
    traverseLeftStatesInner(requests, 0, state, 0);
  }

  int maximumRequests(int n, vector<vector<int>> &requests) {
    total = n;
    mid = requests.size() / 2; // [0, mid - 1], [mid, r - 1]

    constructRightStates(requests);
    traverseLeftStates(requests);

    return maxRequests;
  }
};

// 1. Naive
// O(n * 2^n)

// 2. Meet in the middle
// requests를 2개로 쪼개고, 한 쪽에서 발생한 변화의 정 반대가 반대 쪽에서 발생한
// 변화로 표현 가능한지 확인할 수 있음. O(n * 2^(n / 2)) state는 vector로 표현.
// 빌딩 n개, 최대 -16 ~ 16 -> 6비트 필요 -> 6n < 128비트 필요. 128비트 수가
// 없으므로 쪼개서 사용하거나, 그냥 vector로 표현.
