from unittest import TestCase

from leetcodepy.next_permutation import *

SOLUTION1 = Solution1()


def NUMS1():
    return [1, 2, 3]


EXPECTED1 = [1, 3, 2]


def NUMS2():
    return [3, 2, 1]


EXPECTED2 = [1, 2, 3]


def NUMS3():
    return [1, 1, 5]


EXPECTED3 = [1, 5, 1]


def NUMS4():
    return [1]


EXPECTED4 = [1]


class TestNextPermutation(TestCase):
    def test1(self):
        nums1 = NUMS1()
        SOLUTION1.nextPermutation(nums1)
        self.assertListEqual(EXPECTED1, nums1)

        nums2 = NUMS2()
        SOLUTION1.nextPermutation(nums2)
        self.assertListEqual(EXPECTED2, nums2)

        nums3 = NUMS3()
        SOLUTION1.nextPermutation(nums3)
        self.assertListEqual(EXPECTED3, nums3)

        nums4 = NUMS4()
        SOLUTION1.nextPermutation(nums4)
        self.assertListEqual(EXPECTED4, nums4)
