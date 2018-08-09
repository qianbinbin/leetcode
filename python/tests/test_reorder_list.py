from unittest import TestCase

from leetcodepy.reorder_list import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values1 = (1, 2, 3, 4)

expected1 = linked_lists.from_values(1, 4, 2, 3)

values2 = (1, 2, 3, 4, 5)

expected2 = linked_lists.from_values(1, 5, 2, 4, 3)


class TestReorderList(TestCase):
    def test1(self):
        head1 = linked_lists.from_values(*values1)
        solution1.reorderList(head1)
        self.assertTrue(linked_lists.equals(expected1, head1))

        head2 = linked_lists.from_values(*values2)
        solution1.reorderList(head2)
        self.assertTrue(linked_lists.equals(expected2, head2))
