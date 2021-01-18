"""
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
"""
from queue import Queue
from typing import Optional

from .utils import TreeNode


class Solution1:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        return self.is_symmetric(root.left, root.right)

    def is_symmetric(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 is None and root2 is None:
            return True
        if root1 is None or root2 is None:
            return False
        if root1 is root2:
            raise ValueError
        if root1.val != root2.val:
            return False
        return self.is_symmetric(root1.left, root2.right) and self.is_symmetric(root1.right, root2.left)


class Solution2:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        q = Queue()
        q.put(root.left)
        q.put(root.right)
        while not q.empty():
            node1, node2 = q.get(), q.get()
            if node1 is None and node2 is None:
                continue
            if node1 is None or node2 is None:
                return False
            if node1.val != node2.val:
                return False
            q.put(node1.left)
            q.put(node2.right)
            q.put(node1.right)
            q.put(node2.left)
        return True
