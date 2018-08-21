from unittest import TestCase

from leetcodepy.jump_game_ii import *

solution1 = Solution1()

nums = [2, 3, 1, 1, 4]

expected = 2


class TestJumpGameII(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.jump(nums))
