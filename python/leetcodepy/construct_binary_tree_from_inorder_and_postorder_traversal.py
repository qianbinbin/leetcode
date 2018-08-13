"""
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
"""
from typing import List

from .utils import TreeNode


class Solution1:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder:
            return None
        i = inorder.index(postorder[-1])
        root = TreeNode(postorder[-1])
        root.left = self.buildTree(inorder[:i], postorder[:i])
        root.right = self.buildTree(inorder[i + 1:], postorder[i: -1])
        return root
