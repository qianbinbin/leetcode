from unittest import TestCase

from leetcodepy.count_and_say import *

SOLUTION1 = Solution1()

N1 = 1
EXPECTED1 = "1"

N2 = 4
EXPECTED2 = "1211"


class TestCountAndSay(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.countAndSay(N1))
        self.assertEqual(EXPECTED2, SOLUTION1.countAndSay(N2))
