from unittest import TestCase

from leetcodepy.reverse_linked_list_ii import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

values = (1, 2, 3, 4, 5)

m, n = 2, 4

expected = linked_lists.from_values(1, 4, 3, 2, 5)


class TestReverseLinkedListII(TestCase):
    def test1(self):
        head = linked_lists.from_values(*values)
        head = solution1.reverseBetween(head, m, n)
        self.assertTrue(linked_lists.equals(expected, head))
