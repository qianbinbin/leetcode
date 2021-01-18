from unittest import TestCase

from leetcodepy.best_time_to_buy_and_sell_stock_ii import *

solution1 = Solution1()

prices1 = [7, 1, 5, 3, 6, 4]

expected1 = 7

prices2 = [1, 2, 3, 4, 5]

expected2 = 4

prices3 = [7, 6, 4, 3, 1]

expected3 = 0


class TestBestTimeToBuyAndSellStockII(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.maxProfit(prices1))
        self.assertEqual(expected2, solution1.maxProfit(prices2))
        self.assertEqual(expected3, solution1.maxProfit(prices3))
