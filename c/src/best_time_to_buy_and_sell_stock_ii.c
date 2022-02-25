#include "best_time_to_buy_and_sell_stock_ii.h"

int maxProfit_122_1(int *prices, int pricesSize) {
    int ret = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] > prices[i - 1])
            ret += prices[i] - prices[i - 1];
    }
    return ret;
}
