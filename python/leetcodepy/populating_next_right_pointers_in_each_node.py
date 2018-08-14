"""
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
"""
from typing import Optional

from .utils import TreeLinkNode


class Solution1:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root: Optional[TreeLinkNode]):
        if root is None:
            return
        if root.left is not None:
            root.left.next = root.right
            if root.next is not None:
                root.right.next = root.next.left
            self.connect(root.left)
            self.connect(root.right)


class Solution2:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root: Optional[TreeLinkNode]):
        if root is None:
            return
        node = root
        dummy = TreeLinkNode(0)
        tail = dummy
        while node.left is not None:
            while node is not None:
                tail.next = node.left
                tail = tail.next
                tail.next = node.right
                tail = tail.next
                node = node.next
            node = dummy.next
            tail = dummy
