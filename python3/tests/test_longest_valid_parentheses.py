from unittest import TestCase

from leetcodepy.longest_valid_parentheses import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()
SOLUTION3 = Solution3()

S1 = "(()"
EXPECTED1 = 2

S2 = ")()())"
EXPECTED2 = 4

S3 = ""
EXPECTED3 = 0


class TestLongestValidParentheses(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.longestValidParentheses(S1))
        self.assertEqual(EXPECTED2, SOLUTION1.longestValidParentheses(S2))
        self.assertEqual(EXPECTED3, SOLUTION1.longestValidParentheses(S3))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.longestValidParentheses(S1))
        self.assertEqual(EXPECTED2, SOLUTION2.longestValidParentheses(S2))
        self.assertEqual(EXPECTED3, SOLUTION2.longestValidParentheses(S3))

    def test3(self):
        self.assertEqual(EXPECTED1, SOLUTION3.longestValidParentheses(S1))
        self.assertEqual(EXPECTED2, SOLUTION3.longestValidParentheses(S2))
        self.assertEqual(EXPECTED3, SOLUTION3.longestValidParentheses(S3))
