"""
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        self.pre_order(root, result)
        return result

    def pre_order(self, root: Optional[TreeNode], result: List[int]):
        if root is None:
            return
        result.append(root.val)
        self.pre_order(root.left, result)
        self.pre_order(root.right, result)
