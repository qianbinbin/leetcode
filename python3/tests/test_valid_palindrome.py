from unittest import TestCase

from leetcodepy.valid_palindrome import *

SOLUTION1 = Solution1()

S1 = "A man, a plan, a canal: Panama"
EXPECTED1 = True

S2 = "race a car"
EXPECTED2 = False

S3 = " "
EXPECTED3 = True


class TestValidPalindrome(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.isPalindrome(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.isPalindrome(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.isPalindrome(S3))
