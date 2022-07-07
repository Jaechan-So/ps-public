// 2178. Maximum Split of Positive Even Integers
// https://leetcode.com/problems/maximum-split-of-positive-even-integers/

using namespace std;

#include <vector>

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> answer;
        if(isOdd(finalSum)) {
            return answer;
        }

        // If we found 'n' such that n(n+1)/2 <= halfSum < (n+1)(n+2)/2, where halfSum == finalSum / 2,
        // then the answer array is consist of 1 ~ n, followed by adding halfSum - n(n+1)/2 to the last elem n, followed by multiplying 2 for all elements.
        // i.e. n(n+1) <= finalSum < (n+1)(n+2)

        // Find 'n' such that n(n+1)/2 <= halfSum < (n+1)(n+2)/2, where halfSum == finalSum / 2.
        long long n = 0;
        for(long long i = 1; i < 100000; i++) {
            if(i*(i+1) <= finalSum && finalSum < (i+1)*(i+2)) {
                n = i;
                break;
            }
        }

        // The answer array is consist of 1 ~ n, followed by adding halfSum - n(n+1)/2 to the last elem n, and...
        for(long long i = 1; i < n; i++) {
            answer.push_back(i);
        }
        answer.push_back(n + (finalSum - n*(n+1))/2);

        // Multiply 2 for all elements.
        for(long long i = 0; i < n; i++) {
            answer[i] = answer[i] * 2;
        }

        return answer;
    }
    bool isOdd(long long ll) {
        return ll % 2 != 0;
    }
};
