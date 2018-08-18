from unittest import TestCase

from leetcodepy.insertion_sort_list import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values1 = (4, 2, 1, 3)

expected1 = linked_lists.from_values(1, 2, 3, 4)

values2 = (-1, 5, 3, 4, 0)

expected2 = linked_lists.from_values(-1, 0, 3, 4, 5)


class TestInsertionSortList(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(expected1, solution1.insertionSortList(linked_lists.from_values(*values1))))
        self.assertTrue(linked_lists.equals(expected2, solution1.insertionSortList(linked_lists.from_values(*values2))))
