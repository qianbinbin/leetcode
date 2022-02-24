from unittest import TestCase

from leetcodepy.best_time_to_buy_and_sell_stock import *

SOLUTION1 = Solution1()

PRICES1 = [7, 1, 5, 3, 6, 4]
EXPECTED1 = 5

PRICES2 = [7, 6, 4, 3, 1]
EXPECTED2 = 0


class TestBestTimeToBuyAndSellStock(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxProfit(PRICES1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxProfit(PRICES2))
