"""
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.



Example 1:
https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n


Follow up: Could you do it in one pass?
"""
from typing import Optional

from .utils import ListNode


class Solution1:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        tail = dummy
        for i in range(left - 1):
            tail = tail.next
        first = tail.next
        for i in range(left, right):
            p = first.next
            first.next = p.next
            p.next = tail.next
            tail.next = p
        return dummy.next
