from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def from_values(*args: int) -> Optional[ListNode]:
    dummy = ListNode()
    tail = dummy
    for v in args:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


def equals(l1: Optional[ListNode], l2: Optional[ListNode]) -> bool:
    if l1 is l2:
        return True
    while l1 is not None and l2 is not None and l1.val == l2.val:
        l1 = l1.next
        l2 = l2.next
    return l1 is None and l2 is None


class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
