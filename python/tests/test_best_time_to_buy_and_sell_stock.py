from unittest import TestCase

from leetcodepy.best_time_to_buy_and_sell_stock import *

solution1 = Solution1()

prices1 = [7, 1, 5, 3, 6, 4]

expected1 = 5

prices2 = [7, 6, 4, 3, 1]

expected2 = 0


class TestBestTimeToBuyAndSellStock(TestCase):
    def test1(self):
        self.assertEqual(expected1, solution1.maxProfit(prices1))
        self.assertEqual(expected2, solution1.maxProfit(prices2))
