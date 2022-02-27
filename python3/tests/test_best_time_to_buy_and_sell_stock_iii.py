from unittest import TestCase

from leetcodepy.best_time_to_buy_and_sell_stock_iii import *

SOLUTION1 = Solution1()
SOLUTION2 = Solution2()

PRICES1 = [3, 3, 5, 0, 0, 3, 1, 4]
EXPECTED1 = 6

PRICES2 = [1, 2, 3, 4, 5]
EXPECTED2 = 4

PRICES3 = [7, 6, 4, 3, 1]
EXPECTED3 = 0


class TestBestTimeToBuyAndSellStockIII(TestCase):
    def test1(self):
        self.assertEqual(EXPECTED1, SOLUTION1.maxProfit(PRICES1))
        self.assertEqual(EXPECTED2, SOLUTION1.maxProfit(PRICES2))
        self.assertEqual(EXPECTED3, SOLUTION1.maxProfit(PRICES3))

    def test2(self):
        self.assertEqual(EXPECTED1, SOLUTION2.maxProfit(PRICES1))
        self.assertEqual(EXPECTED2, SOLUTION2.maxProfit(PRICES2))
        self.assertEqual(EXPECTED3, SOLUTION2.maxProfit(PRICES3))
