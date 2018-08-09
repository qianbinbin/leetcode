from unittest import TestCase

from leetcodepy.rotate_list import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values1 = (1, 2, 3, 4, 5)

k1 = 2

expected1 = linked_lists.from_values(4, 5, 1, 2, 3)

values2 = (0, 1, 2)

k2 = 4

expected2 = linked_lists.from_values(2, 0, 1)


class TestRotateList(TestCase):
    def test1(self):
        head1 = linked_lists.from_values(*values1)
        head1 = solution1.rotateRight(head1, k1)
        self.assertTrue(linked_lists.equals(expected1, head1))

        head2 = linked_lists.from_values(*values2)
        head2 = solution1.rotateRight(head2, k2)
        self.assertTrue(linked_lists.equals(expected2, head2))
