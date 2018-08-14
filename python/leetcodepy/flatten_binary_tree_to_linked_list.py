"""
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.pre_order_flatten(root, [None])

    def pre_order_flatten(self, root: Optional[TreeNode], pre: List[Optional[TreeNode]]):
        if root is None:
            return
        right = root.right
        if pre[0] is not None:
            pre[0].left = None
            pre[0].right = root
        pre[0] = root
        self.pre_order_flatten(root.left, pre)
        self.pre_order_flatten(right, pre)
