from unittest import TestCase

from leetcodepy.rotate_list import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()

VALUES1 = (1, 2, 3, 4, 5)
K1 = 2
EXPECTED1 = linked_lists.from_values(4, 5, 1, 2, 3)

VALUES2 = (0, 1, 2)
K2 = 4
EXPECTED2 = linked_lists.from_values(2, 0, 1)


class TestRotateList(TestCase):
    def test1(self):
        head1 = linked_lists.from_values(*VALUES1)
        head1 = SOLUTION1.rotateRight(head1, K1)
        self.assertTrue(linked_lists.equals(EXPECTED1, head1))

        head2 = linked_lists.from_values(*VALUES2)
        head2 = SOLUTION1.rotateRight(head2, K2)
        self.assertTrue(linked_lists.equals(EXPECTED2, head2))
