from unittest import TestCase

from leetcodepy.palindrome_number import *

solution1 = Solution1()

x1 = 121

x2 = -121

x3 = 10


class TestPalindromeNumber(TestCase):
    def test1(self):
        self.assertTrue(solution1.isPalindrome(x1))
        self.assertFalse(solution1.isPalindrome(x2))
        self.assertFalse(solution1.isPalindrome(x3))
