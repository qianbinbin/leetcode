from unittest import TestCase

from leetcodepy.remove_duplicates_from_sorted_list_ii import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 2, 3, 3, 4, 4, 5)


EXPECTED1 = linked_lists.from_values(1, 2, 5)


def HEAD2():
    return linked_lists.from_values(1, 1, 1, 2, 3)


EXPECTED2 = linked_lists.from_values(2, 3)


class TestRemoveDuplicatesFromSortedListII(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.deleteDuplicates(HEAD1())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.deleteDuplicates(HEAD2())))
