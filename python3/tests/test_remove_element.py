from unittest import TestCase

from leetcodepy.remove_element import *

SOLUTION1 = Solution1()


def NUMS1():
    return [3, 2, 2, 3]


VAL1 = 3
EXPECTED1 = [2, 2]


def NUMS2():
    return [0, 1, 2, 2, 3, 0, 4, 2]


VAL2 = 2
EXPECTED2 = [0, 1, 3, 0, 4]


class TestRemoveElement(TestCase):
    def test1(self):
        nums1 = NUMS1()
        size1 = SOLUTION1.removeElement(nums1, VAL1)
        self.assertListEqual(EXPECTED1, nums1[:size1])

        nums2 = NUMS2()
        size2 = SOLUTION1.removeElement(nums2, VAL2)
        self.assertListEqual(EXPECTED2, nums2[:size2])
