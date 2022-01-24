from unittest import TestCase

from leetcodepy.remove_duplicates_from_sorted_list import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()


def HEAD1():
    return linked_lists.from_values(1, 1, 2)


EXPECTED1 = linked_lists.from_values(1, 2)


def HEAD2():
    return linked_lists.from_values(1, 1, 2, 3, 3)


EXPECTED2 = linked_lists.from_values(1, 2, 3)


class TestRemoveDuplicatesFromSortedList(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.deleteDuplicates(HEAD1())))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.deleteDuplicates(HEAD2())))
