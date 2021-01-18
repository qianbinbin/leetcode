from unittest import TestCase

from leetcodepy.remove_duplicates_from_sorted_list_ii import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values1 = (1, 2, 3, 3, 4, 4, 5)

expected1 = linked_lists.from_values(1, 2, 5)

values2 = (1, 1, 1, 2, 3)

expected2 = linked_lists.from_values(2, 3)


class TestRemoveDuplicatesFromSortedListII(TestCase):
    def test1(self):
        head1 = linked_lists.from_values(*values1)
        head1 = solution1.deleteDuplicates(head1)
        self.assertTrue(linked_lists.equals(expected1, head1))

        head2 = linked_lists.from_values(*values2)
        head2 = solution1.deleteDuplicates(head2)
        self.assertTrue(linked_lists.equals(expected2, head2))
