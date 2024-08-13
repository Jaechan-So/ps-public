# 297. Serialize and Deserialize Binary Tree
# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root) -> str:
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return "()"
        left, right = self.serialize(root.left), self.serialize(root.right)
        return f"({root.val} {left} {right})"

    def deserialize(self, data) -> 'TreeNode':
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        return self.deserializeUnwrap(data, 0)[0]

    def deserializeUnwrap(self, data: str, index: int) -> tuple['TreeNode', int]:
        if data[index] == "(" and data[index + 1] == ")":
            return None, index + 1

        startIndex = index + 1
        while data[index] != " ":
            index += 1
        val = int(data[startIndex:index + 1])

        node = TreeNode(val)

        index += 1
        left, index = self.deserializeUnwrap(data, index)
        node.left = left

        index += 2
        right, index = self.deserializeUnwrap(data, index)
        node.right = right

        return node, index + 1

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
