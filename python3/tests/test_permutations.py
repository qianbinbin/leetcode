from unittest import TestCase

from leetcodepy.permutations import *

SOLUTION1 = Solution1()

NUMS1 = [1, 2, 3]
EXPECTED1 = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]

NUMS2 = [0, 1]
EXPECTED2 = [[0, 1], [1, 0]]

NUMS3 = [1]
EXPECTED3 = [[1]]


class TestPermutations(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.permute(NUMS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.permute(NUMS2))
        self.assertListEqual(EXPECTED3, SOLUTION1.permute(NUMS3))
