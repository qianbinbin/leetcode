from unittest import TestCase

from three_sum_closest import *

solution1 = Solution1()

nums = [-1, 2, 1, -4]

target = 1

expected = 2


class TestThreeSumClosest(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.threeSumClosest(nums, target))
