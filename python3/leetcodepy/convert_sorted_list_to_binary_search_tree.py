"""
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
"""
from typing import List, Optional

from .utils import ListNode, TreeNode


class Solution1:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        size = 0
        p = head
        while p is not None:
            p = p.next
            size += 1
        return self.sorted_list_to_bst([head], 0, size)

    def sorted_list_to_bst(self, head: List[Optional[ListNode]], start: int, end: int) -> Optional[TreeNode]:
        if start == end:
            return None
        mid = (start + end) // 2
        left = self.sorted_list_to_bst(head, start, mid)
        root = TreeNode(head[0].val)
        head[0] = head[0].next
        root.left = left
        root.right = self.sorted_list_to_bst(head, mid + 1, end)
        return root
