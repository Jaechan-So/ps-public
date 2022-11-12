// 1220. Count Vowels Permutation
// https://leetcode.com/problems/count-vowels-permutation/

using namespace std;

class Solution {
public:
  int countVowelPermutation(int n) {
    long long previousPermutations[5] = {1, 1, 1, 1, 1};
    long long currentPermutations[5] = {1, 1, 1, 1, 1};

    for (int i = 2; i <= n; i++) {
      currentPermutations[0] =
          getModulo(previousPermutations[1] + previousPermutations[2] +
                    previousPermutations[4]);
      currentPermutations[1] =
          getModulo(previousPermutations[0] + previousPermutations[2]);
      currentPermutations[2] =
          getModulo(previousPermutations[1] + previousPermutations[3]);
      currentPermutations[3] = getModulo(previousPermutations[2]);
      currentPermutations[4] =
          getModulo(previousPermutations[2] + previousPermutations[3]);

      for (int j = 0; j < 5; j++) {
        previousPermutations[j] = currentPermutations[j];
      }
    }

    long long answer = 0;
    for (int i = 0; i < 5; i++) {
      answer += getModulo(currentPermutations[i]);
    }

    return getModulo(answer);
  }

  long long getModulo(long long l) { return l % 1000000007; }
};
