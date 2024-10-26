# 2458. Height of Binary Tree After Subtree Removal Queries
# https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description

from typing import *

# 1. Naive Solution
# 매 쿼리마다 DFS를 돌면서, 최대 높이를 저장한다. 이 때, 쿼리로 들어온 노드를 찾으면 더 이상 탐색하지 않는다.
# T(mn), S(logn)
# 따라서, 직접 DFS를 돌아서 T(n)이 걸리는 부분을 개선해야 함

# 2. Improvement 1
# 특정 서브트리를 제거할 때, 그 서브트리의 루트 노드부터 위로 올라가면서 높이를 다시 계산하는 작업을 거칠 수 있을 것 같다.
# 그러기 위해서는 각 노드별로 좌, 우의 높이를 미리 계산해둬야 한다.
# 또한 각 노드의 부모도 미리 계산해둬야 한다.
# 각 노드의 값은 유일하므로, Hash Map에 값을 저장해둘 수 있다.
# T(n + mlogn), S(n)

# 3. Improvement 2 (Discussion)
# 특정 서브트리를 제거했을 때, 해당 서브트리로 오는 경로를 제외한 다른 모든 경로에 대한 최대 높이가 구해야 하는 값이 된다.
# DFS를 이용해서, 각 노드에 대한 최대 높이를 미리 계산해둔다.
# 다시 DFS로 순회하면서, 자식 노드로 진입하기 전에 다른 자식 노드에 대한 최대 높이를 미리 구해서 진입하면 된다.
# 이를 통해서, 각 노드별로 서브트리를 제거했을 때 최대 높이를 구할 수 있다.
# T(n + q), S(n)

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.valueToHeight = dict()
        self.result = dict()

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        self.traverseForHeight(root)
        self.traverseForMaxHeightWithoutNode(root, 0, 0)
        return [self.result[query] for query in queries]

    def traverseForHeight(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0

        height = 0
        for child in [node.left, node.right]:
            if child:
                height = max(height, 1 + self.traverseForHeight(child))

        self.valueToHeight[node.val] = height
        return self.valueToHeight[node.val]

    def traverseForMaxHeightWithoutNode(self, node: Optional[TreeNode], depth: int, cumulativeMax: int) -> None:
        if not node:
            return

        self.result[node.val] = cumulativeMax

        if node.left:
            candidate = depth + 1 + self.valueToHeight[node.right.val] if node.right else depth
            self.traverseForMaxHeightWithoutNode(node.left, depth + 1, max(cumulativeMax, candidate))

        if node.right:
            candidate = depth + 1 + self.valueToHeight[node.left.val] if node.left else depth
            self.traverseForMaxHeightWithoutNode(node.right, depth + 1, max(cumulativeMax, candidate))
