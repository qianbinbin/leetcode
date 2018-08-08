from unittest import TestCase

from leetcodepy.sort_colors import *

solution1 = Solution1()

expected = [0, 0, 1, 1, 2, 2]


class TestSortColors(TestCase):
    def test1(self):
        nums = [2, 0, 2, 1, 1, 0]
        solution1.sortColors(nums)
        self.assertListEqual(expected, nums)
