"""
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

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

    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        self.in_order(root, result)
        return result
