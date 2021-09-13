from unittest import TestCase

from leetcodepy.jump_game import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

NUMS1 = [2, 3, 1, 1, 4]
EXPECTED1 = True

NUMS2 = [3, 2, 1, 0, 4]
EXPECTED2 = False


class TestJumpGame(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.canJump(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION1.canJump(NUMS2))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.canJump(NUMS1))
        self.assertEqual(EXPECTED2, SOLUTION2.canJump(NUMS2))
