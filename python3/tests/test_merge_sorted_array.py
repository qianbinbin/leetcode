from unittest import TestCase

from leetcodepy.merge_sorted_array import *

SOLUTION1 = Solution1()


def NUMS11():
    return [1, 2, 3, 0, 0, 0]


M1 = 3

NUMS12 = [2, 5, 6]
N1 = 3
EXPECTED1 = [1, 2, 2, 3, 5, 6]


def NUMS21():
    return [1]


M2 = 1

NUMS22 = []
N2 = 0
EXPECTED2 = [1]


def NUMS31():
    return [0]


M3 = 0

NUMS32 = [1]
N3 = 1
EXPECTED3 = [1]


class TestMergeSortedArray(TestCase):
    def test1(self):
        nums1 = NUMS11()
        SOLUTION1.merge(nums1, M1, NUMS12, N1)
        self.assertListEqual(EXPECTED1, nums1)

        nums2 = NUMS21()
        SOLUTION1.merge(nums2, M2, NUMS22, N2)
        self.assertListEqual(EXPECTED2, nums2)

        nums3 = NUMS31()
        SOLUTION1.merge(nums3, M3, NUMS32, N3)
        self.assertListEqual(EXPECTED3, nums3)
