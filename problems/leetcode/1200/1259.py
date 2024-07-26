# 1259. Handshakes That Don't Cross
# https://leetcode.com/problems/handshakes-that-dont-cross/description

# 일단 DP의 한 종류임.
# 하나의 handshake가 생기면, 반드시 2개의 partition이 생김. 해당 partition을 나누는 방법은 DP로 구해야 함.
# handshake의 개수의 기준은 그냥 하나를 잡아서 하면 알아서 모든 경우의 수를 다 따질 수 있음.
# 양 옆 - 가능, 1칸 띄고 - 불가능 (handshake가 생기면 딱 1개 node만 남는 경우가 생김), 그 이후 - 가능

class Solution:
    def __init__(self):
        self.results = dict()
        self.results[0] = 1
        self.results[2] = 1
        self.mod = int(1e9 + 7)

    def numberOfWays(self, numPeople: int) -> int:
        if numPeople in self.results:
            return self.results[numPeople]

        totalWays = 0
        middle = 1 + (numPeople // 2)
        for target in range(2, middle + 1):
            if target == 3:
                continue

            eachWay = ((self.numberOfWays(target - 2) % self.mod) * (self.numberOfWays(numPeople - target) % self.mod)) % self.mod

            duplicate = 1 if target == middle else 2
            totalWays += (duplicate * eachWay)
            totalWays = totalWays % self.mod

        self.results[numPeople] = totalWays
        return self.results[numPeople]
