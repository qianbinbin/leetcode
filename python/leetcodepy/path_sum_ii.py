"""
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
"""
from typing import List

from .utils import TreeNode


class Solution1:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        result = []
        if root is None:
            return result
        self.pre_order_path_sum(root, 0, sum, result, [])
        return result

    def pre_order_path_sum(self, root: TreeNode, path_sum: int, target: int, result: List[List[int]], path: List[int]):
        path.append(root.val)
        path_sum += root.val
        if root.left is None and root.right is None:
            if path_sum == target:
                result.append(path[:])
            path.pop()
            return
        if root.left is not None:
            self.pre_order_path_sum(root.left, path_sum, target, result, path)
        if root.right is not None:
            self.pre_order_path_sum(root.right, path_sum, target, result, path)
        path.pop()
