# 1110. Delete Nodes And Return Forest
# https://leetcode.com/problems/delete-nodes-and-return-forest/description

from collections import deque
from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        roots = []
        removals = set(to_delete)
        if root and root.val not in removals:
            roots.append(root)

        q = deque()
        if root:
            q.append(root)

        while q:
            node = q.popleft()

            if node.val in removals:
                for child in [node.left, node.right]:
                    if child and child.val not in removals:
                        roots.append(child)

            if node.left:
                q.append(node.left)
                if node.left.val in removals:
                    node.left = None

            if node.right:
                q.append(node.right)
                if node.right.val in removals:
                    node.right = None

        return roots
