"""
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:
https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def pre_order(self, root: Optional[TreeNode], level: int, result: List[List[int]]):
        if root is None:
            return
        if len(result) == level:
            result.append([])
        result[level].append(root.val)
        self.pre_order(root.left, level + 1, result)
        self.pre_order(root.right, level + 1, result)

    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        self.pre_order(root, 0, result)
        for i in range(1, len(result), 2):
            result[i] = result[i][::-1]
        return result


class Solution2:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if root is None:
            return result
        queue = [root]
        reverse = False
        while queue:
            level = []
            nex = []
            for node in queue:
                level.append(node.val)
                if node.left is not None:
                    nex.append(node.left)
                if node.right is not None:
                    nex.append(node.right)
            if reverse:
                level = level[::-1]
            result.append(level)
            reverse = not reverse
            queue = nex
        return result
