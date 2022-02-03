"""
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.



Example 1:
https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:
https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.


Constraints:

The number of nodes in the tree is in the range [2, 1000].
-2^31 <= Node.val <= 2^31 - 1


Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution2:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        result: List[TreeNode] = []
        self.in_order(root, result)
        i, j = 0, len(result) - 1
        while i < j and result[i].val < result[i + 1].val:
            i += 1
        while j > i and result[j].val > result[j - 1].val:
            j -= 1
        result[i].val, result[j].val = result[j].val, result[i].val

    def in_order(self, root: Optional[TreeNode], result: List[TreeNode]) -> None:
        if root is None:
            return
        self.in_order(root.left, result)
        result.append(root)
        self.in_order(root.right, result)


class Solution1:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        pre: List[Optional[TreeNode]] = [None]
        invalid1: List[Optional[TreeNode]] = [None]
        invalid2: List[Optional[TreeNode]] = [None]
        self.in_order(root, pre, invalid1, invalid2)
        invalid1[0].val, invalid2[0].val = invalid2[0].val, invalid1[0].val

    def in_order(self, root: TreeNode, pre: List[Optional[TreeNode]],
                 invalid1: List[Optional[TreeNode]], invalid2: List[Optional[TreeNode]]):
        if root is None:
            return
        self.in_order(root.left, pre, invalid1, invalid2)
        if pre[0] is not None and pre[0].val >= root.val:
            if invalid1[0] is None:
                invalid1[0] = pre[0]
            invalid2[0] = root
        pre[0] = root
        self.in_order(root.right, pre, invalid1, invalid2)
