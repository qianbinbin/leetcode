"""
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        self.post_order(root, result)
        return result

    def post_order(self, root: Optional[TreeNode], result: List[int]):
        if root is None:
            return
        self.post_order(root.left, result)
        self.post_order(root.right, result)
        result.append(root.val)
