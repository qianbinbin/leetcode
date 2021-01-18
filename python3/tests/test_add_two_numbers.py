from unittest import TestCase

from leetcodepy.add_two_numbers import *
from leetcodepy.utils import linked_lists

solution1 = Solution1()

l1 = linked_lists.from_values(2, 4, 3)

l2 = linked_lists.from_values(5, 6, 4)

expected = linked_lists.from_values(7, 0, 8)


class TestAddTwoNumbers(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(expected, solution1.addTwoNumbers(l1, l2)))
