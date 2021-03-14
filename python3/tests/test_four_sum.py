from unittest import TestCase

from leetcodepy.four_sum import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

NUMS1 = [1, 0, -1, 0, -2, 2]
TARGET1 = 0
EXPECTED1 = [
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1]
]

NUMS2 = []
TARGET2 = 0
EXPECTED2 = []


class TestFourSum(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.fourSum(NUMS1, TARGET1))
        self.assertListEqual(EXPECTED2, SOLUTION1.fourSum(NUMS2, TARGET2))

    def test2(self):
        self.assertSetEqual(
            set([tuple(_) for _ in EXPECTED1]),
            set([tuple(_) for _ in SOLUTION1.fourSum(NUMS1, TARGET1)])
        )
        self.assertListEqual(EXPECTED2, SOLUTION2.fourSum(NUMS2, TARGET2))
