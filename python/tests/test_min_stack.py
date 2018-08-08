from unittest import TestCase

from leetcodepy.min_stack import *

x1, x2, x3 = -2, 0, -3

expected1, expected2, expected3 = -3, 0, -2


class TestMinStack(TestCase):
    def test1(self):
        min_stack = MinStack()
        min_stack.push(x1)
        min_stack.push(x2)
        min_stack.push(x3)
        self.assertEqual(expected1, min_stack.getMin())
        min_stack.pop()
        self.assertEqual(expected2, min_stack.top())
        self.assertEqual(expected3, min_stack.getMin())
