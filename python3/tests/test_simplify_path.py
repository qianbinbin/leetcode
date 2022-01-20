from unittest import TestCase

from leetcodepy.simplify_path import *

SOLUTION1 = Solution1()

PATH1 = "/home/"
EXPECTED1 = "/home"

PATH2 = "/../"
EXPECTED2 = "/"

PATH3 = "/home//foo/"
EXPECTED3 = "/home/foo"


class TestSimplifyPath(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.simplifyPath(PATH1))
        self.assertEqual(EXPECTED2, SOLUTION1.simplifyPath(PATH2))
        self.assertEqual(EXPECTED3, SOLUTION1.simplifyPath(PATH3))
