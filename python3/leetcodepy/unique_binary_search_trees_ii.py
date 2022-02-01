"""
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.



Example 1:
https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg

Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 8
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.generate_trees(1, n + 1)

    def copy_tree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        return TreeNode(root.val, self.copy_tree(root.left), self.copy_tree(root.right))

    def generate_trees(self, start: int, end: int) -> List[Optional[TreeNode]]:
        if start == end:
            return [None]
        result = []
        for i in range(start, end):
            left_trees = self.generate_trees(start, i)
            right_trees = self.generate_trees(i + 1, end)
            for left_tree in left_trees:
                for right_tree in right_trees:
                    result.append(TreeNode(i, self.copy_tree(left_tree), self.copy_tree(right_tree)))
        return result
