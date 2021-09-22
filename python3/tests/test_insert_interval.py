from unittest import TestCase

from leetcodepy.insert_interval import *

SOLUTION1 = Solution1()

INTERVALS1 = [[1, 3], [6, 9]]
NEWINTERVAL1 = [2, 5]
EXPECTED1 = [[1, 5], [6, 9]]


class TestInsertInterval(TestCase):
    def test1(self):
        self.assertListEqual(EXPECTED1, SOLUTION1.insert(INTERVALS1, NEWINTERVAL1))
