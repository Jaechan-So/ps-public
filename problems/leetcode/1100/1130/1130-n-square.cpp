// 1130. Minimum Cost Tree From Leaf Values
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

using namespace std;

#include <vector>

class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int cost = 0, n = arr.size();

    for (int i = 0; i < n - 1; i++) {
      // Find minimum product value and index of minimum value.
      int minimumVal = arr[0] * arr[1], minimumIndex = arr[0] < arr[1] ? 0 : 1;
      for (int j = 1; j < arr.size() - 1; j++) {
        if (arr[j] * arr[j + 1] < minimumVal) {
          minimumVal = arr[j] * arr[j + 1];
          minimumIndex = arr[j] < arr[j + 1] ? j : j + 1;
        }
      }

      // Add cost.
      cost += minimumVal;

      // If we remove index which value is minimum, then it is equivalent to
      // choose the largest value in parent node's subtree.
      arr.erase(arr.begin() + minimumIndex);
    }

    return cost;
  }
};

// 동일한 문제
// arr에서 연속한 두 숫자를 고르고, 그 숫자의 곱을 계속 더해서 가장 작은 수가
// 나오도록 하면 된다. 어차피 곱해서 나오는 결과는 모두 non-leaf node이기 때문에
// 복잡하게 생각할 것 없다. 아 근데 곱하는 케이스가 그냥 무작정 할 수 있는게
// 아니라 정해져 있을 수도..? -> 무작정 해도 됨. 곱이 작은 순서로 연산해나가야
// 최종 값도 작을 것이라고 추측. (Greedy)
