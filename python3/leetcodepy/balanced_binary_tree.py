"""
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

Return false.
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        result = [True]
        self.tree_height(root, result)
        return result[0]

    def tree_height(self, root: Optional[TreeNode], balanced: List[bool]) -> int:
        if root is None:
            return 0
        left_height = self.tree_height(root.left, balanced)
        right_height = self.tree_height(root.right, balanced)
        if abs(left_height - right_height) > 1:
            balanced[0] = False
        return max(left_height, right_height) + 1
