"""
Given the root of a binary tree, return the preorder traversal of its nodes' values.



Example 1:
https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg

Input: root = [1,null,2,3]
Output: [1,2,3]

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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.pre_order(root, result)
        return result

    def pre_order(self, root: Optional[TreeNode], result: List[int]):
        if root is None:
            return
        result.append(root.val)
        self.pre_order(root.left, result)
        self.pre_order(root.right, result)


class Solution2:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if root is None:
            return result
        stack = [root]
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.right is not None:
                stack.append(node.right)
            if node.left is not None:
                stack.append(node.left)
        return result
