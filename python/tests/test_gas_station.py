from unittest import TestCase

from leetcodepy.gas_station import *

solution1 = Solution1()

gas1 = [1, 2, 3, 4, 5]

cost1 = [3, 4, 5, 1, 2]

expected1 = 3

gas2 = [2, 3, 4]

cost2 = [3, 4, 3]

expected2 = -1


class TestGasStation(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.canCompleteCircuit(gas1, cost1))
        self.assertEqual(expected2, solution1.canCompleteCircuit(gas2, cost2))
