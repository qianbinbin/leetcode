"""
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



Example 1:
https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg

Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
"""
from typing import Optional

from .utils import ListNode


class Solution1:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        p = head
        while p:
            if p.next and p.val == p.next.val:
                skip = p.val
                while p and p.val == skip:
                    p = p.next
            else:
                tail.next = p
                tail = p
                p = p.next
        tail.next = None
        return dummy.next
