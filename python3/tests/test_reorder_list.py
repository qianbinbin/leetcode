from unittest import TestCase

from leetcodepy.reorder_list import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 2, 3, 4)


EXPECTED1 = linked_lists.from_values(1, 4, 2, 3)


def HEAD2():
    return linked_lists.from_values(1, 2, 3, 4, 5)


EXPECTED2 = linked_lists.from_values(1, 5, 2, 4, 3)


class TestReorderList(TestCase):
    def test1(self):
        head1 = HEAD1()
        SOLUTION1.reorderList(head1)
        self.assertTrue(linked_lists.equals(EXPECTED1, head1))

        head2 = HEAD2()
        SOLUTION1.reorderList(head2)
        self.assertTrue(linked_lists.equals(EXPECTED2, head2))
