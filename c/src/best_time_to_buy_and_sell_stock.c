#include "best_time_to_buy_and_sell_stock.h"

#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit_121_1(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;
    if (pricesSize < 2) return 0;

    int min_price = prices[0], max_profit = 0;
    for (int i = 1; i < pricesSize; ++i) {
        max_profit = MAX(max_profit, prices[i] - min_price);
        min_price = MIN(min_price, prices[i]);
    }
    return max_profit;
}
