from unittest import TestCase

from leetcodepy.sort_list import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(4, 2, 1, 3)


EXPECTED1 = linked_lists.from_values(1, 2, 3, 4)


def HEAD2():
    return linked_lists.from_values(-1, 5, 3, 4, 0)


EXPECTED2 = linked_lists.from_values(-1, 0, 3, 4, 5)


def HEAD3():
    return linked_lists.from_values()


EXPECTED3 = linked_lists.from_values()


class TestSortList(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.sortList(HEAD1())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.sortList(HEAD2())))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.sortList(HEAD3())))
