"""
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:
https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


Follow up: Can you flatten the tree in-place (with O(1) extra space)?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.pre_order_flatten(root, [None])

    def pre_order_flatten(self, root: Optional[TreeNode], pre: List[Optional[TreeNode]]):
        if root is None:
            return
        if pre[0] is not None:
            pre[0].left = None
            pre[0].right = root
        pre[0] = root
        right = root.right
        self.pre_order_flatten(root.left, pre)
        self.pre_order_flatten(right, pre)


class Solution2:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.reverse_pre_flatten(root, [None])

    def reverse_pre_flatten(self, root: Optional[TreeNode], pre: List[Optional[TreeNode]]):
        if root is None:
            return
        self.reverse_pre_flatten(root.right, pre)
        self.reverse_pre_flatten(root.left, pre)
        root.left = None
        root.right = pre[0]
        pre[0] = root
