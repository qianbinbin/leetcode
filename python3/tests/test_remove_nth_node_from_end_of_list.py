from unittest import TestCase

from leetcodepy.remove_nth_node_from_end_of_list import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 2, 3, 4, 5)


N1 = 2
EXPECTED1 = linked_lists.from_values(1, 2, 3, 5)


def HEAD2():
    return linked_lists.from_values(1)


N2 = 1
EXPECTED2 = None


def HEAD3():
    return linked_lists.from_values(1, 2)


N3 = 1
EXPECTED3 = linked_lists.from_values(1)


class TestRemoveNthNodeFromEndOfList(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.removeNthFromEnd(HEAD1(), N1)))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.removeNthFromEnd(HEAD2(), N2)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.removeNthFromEnd(HEAD3(), N3)))
