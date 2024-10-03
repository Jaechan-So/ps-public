# 285. Inorder Successor in BST
# https://leetcode.com/problems/inorder-successor-in-bst/description/

from typing import *

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        return self.traverseInorderSuccessor(root, p, None)

    def traverseInorderSuccessor(self, node: TreeNode, p: TreeNode, successor: Optional[TreeNode]) -> Optional[TreeNode]:
        if p.val < node.val:
            return self.traverseInorderSuccessor(node.left, p, node)
        elif node.val < p.val:
            return self.traverseInorderSuccessor(node.right, p, successor)
        elif node.right:
            return self.traverseSmallest(node.right)
        else:
            return successor

    def traverseSmallest(self, node: TreeNode) -> TreeNode:
        if node.left:
            return self.traverseSmallest(node.left)
        else:
            return node
