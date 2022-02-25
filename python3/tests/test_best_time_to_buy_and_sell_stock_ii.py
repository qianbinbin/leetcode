from unittest import TestCase

from leetcodepy.best_time_to_buy_and_sell_stock_ii import *

SOLUTION1 = Solution1()

PRICES1 = [7, 1, 5, 3, 6, 4]
EXPECTED1 = 7

PRICES2 = [1, 2, 3, 4, 5]
EXPECTED2 = 4

PRICES3 = [7, 6, 4, 3, 1]
EXPECTED3 = 0


class TestBestTimeToBuyAndSellStockII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxProfit(PRICES1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxProfit(PRICES2))
        self.assertEqual(EXPECTED3, SOLUTION1.maxProfit(PRICES3))
