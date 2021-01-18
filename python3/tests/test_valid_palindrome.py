from unittest import TestCase

from leetcodepy.valid_palindrome import *

solution1 = Solution1()

s1 = "A man, a plan, a canal: Panama"

s2 = "race a car"


class TestValidPalindrome(TestCase):
    def test1(self):
        self.assertTrue(solution1.isPalindrome(s1))
        self.assertFalse(solution1.isPalindrome(s2))
