from unittest import TestCase

from leetcodepy.jump_game_ii import *

SOLUTION1 = Solution1()

NUMS1 = [2, 3, 1, 1, 4]
EXPECTED1 = 2

NUMS2 = [2, 3, 0, 1, 4]
EXPECTED2 = 2


class TestJumpGameII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.jump(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.jump(NUMS2))
