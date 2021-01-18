"""
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
"""
from typing import List

from .utils import TreeNode


class Solution1:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is None:
            return False
        result = [False]
        self.pre_order_path_sum(root, 0, sum, result)
        return result[0]

    def pre_order_path_sum(self, root: TreeNode, path_sum: int, target: int, has: List[bool]):
        if has[0]:
            return
        path_sum += root.val
        if root.left is None and root.right is None:
            if path_sum == target:
                has[0] = True
            return
        if root.left is not None:
            self.pre_order_path_sum(root.left, path_sum, target, has)
        if root.right is not None:
            self.pre_order_path_sum(root.right, path_sum, target, has)
