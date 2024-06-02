# 2102. Sequentially Ordinal Rank Tracker
# https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

# 기본적으로 정렬된 자료구조가 필요함.
# add 했을 때, 마지막으로 query한 결과보다 더 우선순위인 경우에는 포인터를 하나 앞으로 당겨야 함
# 덜 우선순위인 경우에는 상관 X

# better와 worse로 나눈다.
# better는 우선순위가 높은 것들이 담기며, 그 중 우선순위가 가장 낮은 장소가 top인 Priority Queue
# worse는 우선순위가 높은 것들이 담기며, 그 중 우선순위가 가장 높은 장소가 top인 Priority Queue

import heapq


class BetterNode:
    def __init__(self, name: str, score: int):
        self.name = name
        self.score = score

    def __repr__(self):
        return f"(name: {self.name}, score: {self.score})"

    def __lt__(self, other) -> bool:
        if self.score != other.score:
            return self.score < other.score
        return self.name > other.name


class WorseNode:
    def __init__(self, name: str, score: int):
        self.name = name
        self.score = score

    def __repr__(self):
        return f"(name: {self.name}, score: {self.score})"

    def __lt__(self, other) -> bool:
        if self.score != other.score:
            return self.score > other.score
        return self.name < other.name


class SORTracker:
    def __init__(self):
        self.better = []
        self.worse = []

    # 1. add
    # better에 들어가는 경우, better에서 1개를 빼고 worse로 보낸 뒤 better에 넣는다.
    # worse에 들어가는 경우 그냥 넣는다.
    def add(self, name: str, score: int) -> None:
        betterNode = BetterNode(name, score)
        worseNode = WorseNode(name, score)

        if len(self.better) > 0 and betterNode > self.better[0]:
            heapq.heappush(
                self.worse, WorseNode(self.better[0].name, self.better[0].score)
            )
            heapq.heappop(self.better)
            heapq.heappush(self.better, betterNode)
        else:
            heapq.heappush(self.worse, worseNode)

    # 2. get
    # worse의 top이 함수의 반환값이 된다.
    # worse의 top을 하나 빼서 better로 보낸다.
    def get(self) -> str:
        name, score = self.worse[0].name, self.worse[0].score
        heapq.heappush(self.better, BetterNode(name, score))
        heapq.heappop(self.worse)
        return name


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
