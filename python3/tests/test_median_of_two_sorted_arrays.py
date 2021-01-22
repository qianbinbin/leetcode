from unittest import TestCase

from leetcodepy.median_of_two_sorted_arrays import *

SOLUTION1 = Solution1()

NUMS11 = [1, 3]
NUMS12 = [2]
EXPECTED1 = 2.0

NUMS21 = [1, 2]
NUMS22 = [3, 4]
EXPECTED2 = 2.5

NUMS31 = [0, 0]
NUMS32 = [0, 0]
EXPECTED3 = 0.0

NUMS41 = []
NUMS42 = [1]
EXPECTED4 = 1.0

NUMS51 = [2]
NUMS52 = []
EXPECTED5 = 2.0


class TestMedianOfTwoSortedArrays(TestCase):
    def test1(self):
        self.assertAlmostEqual(EXPECTED1, SOLUTION1.findMedianSortedArrays(NUMS11, NUMS12))
        self.assertAlmostEqual(EXPECTED2, SOLUTION1.findMedianSortedArrays(NUMS21, NUMS22))
        self.assertAlmostEqual(EXPECTED3, SOLUTION1.findMedianSortedArrays(NUMS31, NUMS32))
        self.assertAlmostEqual(EXPECTED4, SOLUTION1.findMedianSortedArrays(NUMS41, NUMS42))
        self.assertAlmostEqual(EXPECTED5, SOLUTION1.findMedianSortedArrays(NUMS51, NUMS52))
