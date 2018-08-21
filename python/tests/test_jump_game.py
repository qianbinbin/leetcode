from unittest import TestCase

from leetcodepy.jump_game import *

solution1 = Solution1()

solution2 = Solution2()

nums1 = [2, 3, 1, 1, 4]

nums2 = [3, 2, 1, 0, 4]


class TestJumpGame(TestCase):
    def test1(self):
        self.assertTrue(solution1.canJump(nums1))
        self.assertFalse(solution1.canJump(nums2))

    def test2(self):
        self.assertTrue(solution2.canJump(nums1))
        self.assertFalse(solution2.canJump(nums2))
