from unittest import TestCase

from leetcodepy.permutation_sequence import *

SOLUTION1 = Solution1()

N1, K1 = 3, 3
EXPECTED1 = "213"

N2, K2 = 4, 9
EXPECTED2 = "2314"

N3, K3 = 3, 1
EXPECTED3 = "123"


class TestPermutationSequence(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.getPermutation(N1, K1))
        self.assertEqual(EXPECTED2, SOLUTION1.getPermutation(N2, K2))
        self.assertEqual(EXPECTED3, SOLUTION1.getPermutation(N3, K3))
