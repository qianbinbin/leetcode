from unittest import TestCase

from leetcodepy.merge_two_sorted_lists import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def L11():
    return linked_lists.from_values(1, 2, 4)


def L12():
    return linked_lists.from_values(1, 3, 4)


EXPECTED1 = linked_lists.from_values(1, 1, 2, 3, 4, 4)

L21 = None
L22 = None
EXPECTED2 = linked_lists.from_values()

L31 = None


def L32():
    return linked_lists.from_values(0)


EXPECTED3 = linked_lists.from_values(0)


class TestMergeTwoSortedLists(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.mergeTwoLists(L11(), L12())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.mergeTwoLists(L21, L22)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.mergeTwoLists(L31, L32())))
