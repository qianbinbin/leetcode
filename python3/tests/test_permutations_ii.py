from unittest import TestCase

from leetcodepy.permutations_ii import *

SOLUTION1 = Solution1()

NUMS1 = [1, 1, 2]
EXPECTED1 = [[1, 1, 2], [1, 2, 1], [2, 1, 1]]

NUMS2 = [1, 2, 3]
EXPECTED2 = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]


class TestPermutationsII(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.permuteUnique(NUMS1))
        self.assertListEqual(EXPECTED2, SOLUTION1.permuteUnique(NUMS2))
