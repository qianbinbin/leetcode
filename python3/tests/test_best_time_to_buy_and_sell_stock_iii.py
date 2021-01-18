from unittest import TestCase

from leetcodepy.best_time_to_buy_and_sell_stock_iii import *

solution1 = Solution1()

solution2 = Solution2()

prices1 = [3, 3, 5, 0, 0, 3, 1, 4]

expected1 = 6

prices2 = [1, 2, 3, 4, 5]

expected2 = 4

prices3 = [7, 6, 4, 3, 1]

expected3 = 0


class TestBestTimeToBuyAndSellStockIII(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.maxProfit(prices1))
        self.assertEqual(expected2, solution1.maxProfit(prices2))
        self.assertEqual(expected3, solution1.maxProfit(prices3))

    def test2(self):
        self.assertEqual(expected1, solution2.maxProfit(prices1))
        self.assertEqual(expected2, solution2.maxProfit(prices2))
        self.assertEqual(expected3, solution2.maxProfit(prices3))
