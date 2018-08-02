from unittest import TestCase

from remove_element import *

solution1 = Solution1()

val1 = 3

expected1 = [2, 2]

val2 = 2

expected2 = [0, 1, 3, 0, 4]


class TestRemoveElement(TestCase):
    def test1(self):
        nums1 = [3, 2, 2, 3]
        size1 = solution1.removeElement(nums1, val1)
        self.assertListEqual(expected1, nums1[:size1])

        nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
        size2 = solution1.removeElement(nums2, val2)
        self.assertListEqual(expected2, nums2[:size2])
