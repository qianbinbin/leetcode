from unittest import TestCase

from leetcodepy.palindrome_number import *

SOLUTION1 = Solution1()

X1 = 121
EXPECTED1 = True

X2 = -121
EXPECTED2 = False

X3 = 10
EXPECTED3 = False

X4 = -101
EXPECTED4 = False


class TestPalindromeNumber(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isPalindrome(X1))
        self.assertEqual(EXPECTED2, SOLUTION1.isPalindrome(X2))
        self.assertEqual(EXPECTED3, SOLUTION1.isPalindrome(X3))
        self.assertEqual(EXPECTED4, SOLUTION1.isPalindrome(X4))
