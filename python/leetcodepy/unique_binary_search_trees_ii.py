"""
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n < 1:
            return []
        return self.generate_trees(1, n + 1)

    def copy_tree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        copy = TreeNode(root.val)
        copy.left = self.copy_tree(root.left)
        copy.right = self.copy_tree(root.right)
        return copy

    def generate_trees(self, start: int, end: int) -> List[Optional[TreeNode]]:
        if start == end:
            return [None]
        result = []
        for i in range(start, end):
            left_trees = self.generate_trees(start, i)
            right_trees = self.generate_trees(i + 1, end)
            for left_tree in left_trees:
                for right_tree in right_trees:
                    root = TreeNode(i)
                    root.left = self.copy_tree(left_tree)
                    root.right = self.copy_tree(right_tree)
                    result.append(root)
        return result
