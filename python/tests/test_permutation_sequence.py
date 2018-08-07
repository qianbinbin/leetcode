from unittest import TestCase

from permutation_sequence import *

solution1 = Solution1()

n1, k1 = 3, 3

expected1 = "213"

n2, k2 = 4, 9

expected2 = "2314"


class TestPermutationSequence(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.getPermutation(n1, k1))
        self.assertEqual(expected2, solution1.getPermutation(n2, k2))
