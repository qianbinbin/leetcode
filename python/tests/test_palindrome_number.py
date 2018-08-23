from unittest import TestCase

from leetcodepy.palindrome_number import *

solution1 = Solution1()

solution2 = Solution2()

x1 = 121

x2 = -121

x3 = 10


class TestPalindromeNumber(TestCase):
    def test1(self):
        self.assertTrue(solution1.isPalindrome(x1))
        self.assertFalse(solution1.isPalindrome(x2))
        self.assertFalse(solution1.isPalindrome(x3))

    def test2(self):
        self.assertTrue(solution2.isPalindrome(x1))
        self.assertFalse(solution2.isPalindrome(x2))
        self.assertFalse(solution2.isPalindrome(x3))
