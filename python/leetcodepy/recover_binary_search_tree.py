"""
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2

Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
"""
from typing import List, Optional

from .utils import TreeNode


class Solution1:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        first, second = [None], [None]
        self.in_order(root, [None], first, second)
        if first[0] is not None and second[0] is not None:
            first[0].val, second[0].val = second[0].val, first[0].val

    def in_order(self, root: TreeNode, pre: List[Optional[TreeNode]],
                 first: List[Optional[TreeNode]], second: List[Optional[TreeNode]]):
        if root is None:
            return
        self.in_order(root.left, pre, first, second)
        if pre[0] is not None and pre[0].val >= root.val:
            if first[0] is None:
                first[0] = pre[0]
            second[0] = root
        pre[0] = root
        self.in_order(root.right, pre, first, second)
