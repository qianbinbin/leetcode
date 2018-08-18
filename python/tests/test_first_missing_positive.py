from unittest import TestCase

from leetcodepy.first_missing_positive import *

solution1 = Solution1()

nums1 = [1, 2, 0]

expected1 = 3

nums2 = [3, 4, -1, 1]

expected2 = 2

nums3 = [7, 8, 9, 11, 12]

expected3 = 1


class TestFirstMissingPositive(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.firstMissingPositive(nums1))
        self.assertEqual(expected2, solution1.firstMissingPositive(nums2))
        self.assertEqual(expected3, solution1.firstMissingPositive(nums3))
