"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        self.pre_order(root, 0, result)
        return result

    def pre_order(self, root: Optional[TreeNode], level: int, result: List[List[int]]):
        if root is None:
            return
        if len(result) == level:
            result.append([])
        result[level].append(root.val)
        self.pre_order(root.left, level + 1, result)
        self.pre_order(root.right, level + 1, result)
