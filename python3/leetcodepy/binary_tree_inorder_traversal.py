"""
Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:
https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def in_order(self, root: Optional[TreeNode], result: List[int]):
        if root is None:
            return
        self.in_order(root.left, result)
        result.append(root.val)
        self.in_order(root.right, result)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.in_order(root, result)
        return result


class Solution2:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        node = root
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                result.append(node.val)
                node = node.right
        return result
