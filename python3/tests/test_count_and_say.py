from unittest import TestCase

from leetcodepy.count_and_say import *

solution1 = Solution1()

n1 = 1

expected1 = "1"

n2 = 4

expected2 = "1211"


class TestCountAndSay(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.countAndSay(n1))
        self.assertEqual(expected2, solution1.countAndSay(n2))
