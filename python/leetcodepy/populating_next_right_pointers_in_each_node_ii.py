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

Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
"""
from .utils import TreeLinkNode


class Solution1:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root: TreeLinkNode):
        dummy = TreeLinkNode(0)
        tail = dummy
        node = root
        while node is not None:
            while node is not None:
                if node.left is not None:
                    tail.next = node.left
                    tail = tail.next
                if node.right is not None:
                    tail.next = node.right
                    tail = tail.next
                node = node.next
            node = dummy.next
            dummy.next = None
            tail = dummy
