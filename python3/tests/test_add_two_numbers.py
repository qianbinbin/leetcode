from unittest import TestCase

from leetcodepy.add_two_numbers import *
from leetcodepy.utils import linked_lists

SOLUTION1 = Solution1()

L11 = linked_lists.from_values(2, 4, 3)
L12 = linked_lists.from_values(5, 6, 4)
EXPECTED1 = linked_lists.from_values(7, 0, 8)

L21 = linked_lists.from_values(0)
L22 = linked_lists.from_values(0)
EXPECTED2 = linked_lists.from_values(0)

L31 = linked_lists.from_values(9, 9, 9, 9, 9, 9, 9)
L32 = linked_lists.from_values(9, 9, 9, 9)
EXPECTED3 = linked_lists.from_values(8, 9, 9, 9, 0, 0, 0, 1)


class TestAddTwoNumbers(TestCase):
    def test1(self):
        self.assertTrue(linked_lists.equals(EXPECTED1, SOLUTION1.addTwoNumbers(L11, L12)))
        self.assertTrue(linked_lists.equals(EXPECTED2, SOLUTION1.addTwoNumbers(L21, L22)))
        self.assertTrue(linked_lists.equals(EXPECTED3, SOLUTION1.addTwoNumbers(L31, L32)))
