from unittest import TestCase

from leetcodepy.median_of_two_sorted_arrays import *

solution1 = Solution1()

nums11 = [1, 3]

nums12 = [2]

expected1 = 2.0

nums21 = [1, 2]

nums22 = [3, 4]

expected2 = 2.5


class TestMedianOfTwoSortedArrays(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.findMedianSortedArrays(nums11, nums12))
        self.assertEqual(expected2, solution1.findMedianSortedArrays(nums21, nums22))
