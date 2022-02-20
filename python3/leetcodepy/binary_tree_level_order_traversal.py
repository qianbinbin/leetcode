"""
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



Example 1:
https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
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


class Solution2:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if root is None:
            return result
        queue = [root]
        while queue:
            level = []
            nex = []
            for node in queue:
                level.append(node.val)
                if node.left is not None:
                    nex.append(node.left)
                if node.right is not None:
                    nex.append(node.right)
            queue = nex
            result.append(level)
        return result
