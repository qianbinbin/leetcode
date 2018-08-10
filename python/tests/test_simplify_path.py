from unittest import TestCase

from leetcodepy.simplify_path import *

solution1 = Solution1()

path1 = "/home/"

expected1 = "/home"

path2 = "/a/./b/../../c/"

expected2 = "/c"

path3 = "/../"

expected3 = "/"

path4 = "/home//foo/"

expected4 = "/home/foo"


class TestSimplifyPath(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.simplifyPath(path1))
        self.assertEqual(expected2, solution1.simplifyPath(path2))
        self.assertEqual(expected3, solution1.simplifyPath(path3))
        self.assertEqual(expected4, solution1.simplifyPath(path4))
