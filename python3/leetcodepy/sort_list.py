"""
Given the head of a linked list, return the list after sorting it in ascending order.



Example 1:
https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5


Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
"""
from typing import Optional

from .utils import ListNode


class Solution1:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        dummy = ListNode(0, head)
        slow, fast = dummy, dummy
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
        h1, h2 = head, slow.next
        slow.next = None
        h1, h2 = self.sortList(h1), self.sortList(h2)
        return self.merge(h1, h2)

    @staticmethod
    def merge(h1: ListNode, h2: ListNode):
        dummy = ListNode(0)
        tail = dummy
        while h1 is not None and h2 is not None:
            if h1.val <= h2.val:
                tail.next = h1
                h1 = h1.next
            else:
                tail.next = h2
                h2 = h2.next
            tail = tail.next
        tail.next = h1 if h1 is not None else h2
        return dummy.next
