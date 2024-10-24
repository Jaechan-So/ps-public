# 951. Flip Equivalent Binary Trees
# https://leetcode.com/problems/flip-equivalent-binary-trees/description

from typing import *

# 재귀적으로 확인
# 정방향으로 동일한지, 교차로 동일한지 모르기 때문에 두 케이스 다 검증하면 OK

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if not root1 and not root2:
            return True

        if (root1 and not root2) or (not root1 and root2):
            return False

        return root1.val == root2.val and (
            (self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)) or
            (self.flipEquiv(root1.left, root2.right) and self.flipEquiv(root1.right, root2.left))
        )
