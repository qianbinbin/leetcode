#include "best_time_to_buy_and_sell_stock_ii.h"

#include <stddef.h>

int maxProfit_122_1(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;

    int max_profit = 0;
    int valley;
    int i = 1;
    while (i < pricesSize) {
        while (i < pricesSize && prices[i] <= prices[i - 1]) ++i;
        valley = prices[i - 1];
        while (i < pricesSize && prices[i] >= prices[i - 1]) ++i;
        max_profit += prices[i - 1] - valley;
    }
    return max_profit;
}

int maxProfit_122_2(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;

    int max_profit = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i - 1];
    }
    return max_profit;
}
