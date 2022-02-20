"""
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



Example 1:
https://assets.leetcode.com/uploads/2020/08/17/linked.jpg

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []


Constraints:

The number of nodes in head is in the range [0, 2 * 10^4].
-10^5 <= Node.val <= 10^5
"""
from typing import List, Optional

from .utils import ListNode, TreeNode


class Solution1:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
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
