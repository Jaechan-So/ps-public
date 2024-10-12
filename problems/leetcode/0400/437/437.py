# 437. Path Sum III
# https://leetcode.com/problems/path-sum-iii/description/

from collections import defaultdict
from typing import *

# 경로, 경로 상의 prefix sum과 전체 sum을 모두 알고 있으면 계산 가능.
# 전체 sum - target sum이 prefix sum 안에 존재하는지 확인만 하면 됨.
# 따라서, prefix sum을 map으로 들고 있으면 해결 (개수 저장 필요)
# 이 때 prefix sum에는 0이 들어가 있어야 함. (root부터 시작되는 케이스)

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        prefixSums = defaultdict(int)
        prefixSums[0] = 1
        return self.traverse(root, targetSum, 0, prefixSums)

    def traverse(self, node: Optional[TreeNode], targetSum: int, currentSum: int, prefixSums: defaultdict[int, int]) -> int:
        if not node:
            return 0

        currentSum += node.val
        count = prefixSums[currentSum - targetSum]

        prefixSums[currentSum] += 1
        for child in [node.left, node.right]:
            if child:
                count += self.traverse(child, targetSum, currentSum, prefixSums)
        prefixSums[currentSum] -= 1

        return count
