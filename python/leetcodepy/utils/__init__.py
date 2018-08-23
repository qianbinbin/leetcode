from .linked_lists import ListNode
from .linked_lists import RandomListNode
from .trees import TreeNode
from .trees import TreeLinkNode
from .graphs import UndirectedGraphNode


class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b


class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __eq__(self, other):
        if self is other:
            return True
        if not isinstance(other, Interval):
            return False
        return self.start == other.start and self.end == other.end
