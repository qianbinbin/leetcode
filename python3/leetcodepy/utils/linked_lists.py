from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def from_values(*args: int) -> Optional[ListNode]:
    dummy = ListNode(0)
    tail = dummy
    for v in args:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


def equals(l1: Optional[ListNode], l2: Optional[ListNode]) -> bool:
    if l1 is l2:
        return True
    if l1 is None or l2 is None:
        return False
    if l1.val != l2.val:
        return False
    return equals(l1.next, l2.next)


class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
