"""
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:
https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


Constraints:

The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000
"""
from typing import Optional

from .utils import ListNode


class Solution1:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        fast, slow = head, head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next

        dummy = ListNode(0, slow)
        p = slow.next
        while p is not None:
            slow.next = p.next
            p.next = dummy.next
            dummy.next = p
            p = slow.next

        p1, p2, tail = head, dummy.next, dummy
        while p1 is not slow:
            tail.next = p1
            tail = p1
            p1 = p1.next
            tail.next = p2
            tail = p2
            p2 = p2.next
