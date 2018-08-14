"""
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            raise ValueError
        result = [root.val]
        self.single_path_sum(root, result)
        return result[0]

    def single_path_sum(self, root: Optional[TreeNode], path_sum: List[int]) -> int:
        if root is None:
            return 0
        left = max(0, self.single_path_sum(root.left, path_sum))
        right = max(0, self.single_path_sum(root.right, path_sum))
        path_sum[0] = max(path_sum[0], root.val + left + right)
        return root.val + max(left, right)
