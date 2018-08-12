from unittest import TestCase

from leetcodepy.valid_number import *

solution1 = Solution1()

s1 = "0"

s2 = " 0.1 "

s3 = "abc"

s4 = "1 a"

s5 = "2e10"


class TestValidNumber(TestCase):
    def test1(self):
        self.assertTrue(solution1.isNumber(s1))
        self.assertTrue(solution1.isNumber(s2))
        self.assertFalse(solution1.isNumber(s3))
        self.assertFalse(solution1.isNumber(s4))
        self.assertTrue(solution1.isNumber(s5))
