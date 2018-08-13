"""
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
"""
from typing import List

from .utils import TreeNode


class Solution1:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        if root is None:
            return result
        level = [root]
        while level:
            values = []
            nex = []
            for node in level:
                values.append(node.val)
                if node.left is not None:
                    nex.append(node.left)
                if node.right is not None:
                    nex.append(node.right)
            result.append(values)
            level = nex
        result.reverse()
        return result
