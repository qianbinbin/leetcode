from unittest import TestCase

from leetcodepy.gas_station import *

SOLUTION1 = Solution1()

GAS1 = [1, 2, 3, 4, 5]
COST1 = [3, 4, 5, 1, 2]
EXPECTED1 = 3

GAS2 = [2, 3, 4]
COST2 = [3, 4, 3]
EXPECTED2 = -1


class TestGasStation(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.canCompleteCircuit(GAS1, COST1))
        self.assertEqual(EXPECTED2, SOLUTION1.canCompleteCircuit(GAS2, COST2))
