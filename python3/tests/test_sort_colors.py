from unittest import TestCase

from leetcodepy.sort_colors import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()


def NUMS1():
    return [2, 0, 2, 1, 1, 0]


EXPECTED1 = [0, 0, 1, 1, 2, 2]


def NUMS2():
    return [2, 0, 1]


EXPECTED2 = [0, 1, 2]


class TestSortColors(TestCase):
    def test1(self):
        nums1 = NUMS1()
        SOLUTION1.sortColors(nums1)
        self.assertListEqual(EXPECTED1, nums1)

        nums2 = NUMS2()
        SOLUTION1.sortColors(nums2)
        self.assertListEqual(EXPECTED2, nums2)

    def test2(self):
        nums1 = NUMS1()
        SOLUTION2.sortColors(nums1)
        self.assertListEqual(EXPECTED1, nums1)

        nums2 = NUMS2()
        SOLUTION2.sortColors(nums2)
        self.assertListEqual(EXPECTED2, nums2)
