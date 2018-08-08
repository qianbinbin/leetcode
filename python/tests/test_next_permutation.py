from unittest import TestCase

from leetcodepy.next_permutation import *

solution1 = Solution1()

expected1 = [1, 3, 2]

expected2 = [1, 2, 3]

expected3 = [1, 5, 1]


class TestNextPermutation(TestCase):
    def test1(self):
        nums1 = [1, 2, 3]
        solution1.nextPermutation(nums1)
        self.assertListEqual(expected1, nums1)

        nums2 = [3, 2, 1]
        solution1.nextPermutation(nums2)
        self.assertListEqual(expected2, nums2)

        nums3 = [1, 1, 5]
        solution1.nextPermutation(nums3)
        self.assertListEqual(expected3, nums3)
