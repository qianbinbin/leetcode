from unittest import TestCase

from leetcodepy.three_sum_closest import *

SOLUTION1 = Solution1()

NUMS1 = [-1, 2, 1, -4]
TARGET1 = 1
EXPECTED1 = 2


class TestThreeSumClosest(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.threeSumClosest(NUMS1, TARGET1))
