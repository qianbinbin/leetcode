"""
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.is_valid_bst(root, [None])

    def is_valid_bst(self, root: TreeNode, pre: List[Optional[TreeNode]]) -> bool:
        if root is None:
            return True
        if not self.is_valid_bst(root.left, pre):
            return False
        if pre[0] is not None and pre[0].val >= root.val:
            return False
        pre[0] = root
        return self.is_valid_bst(root.right, pre)
