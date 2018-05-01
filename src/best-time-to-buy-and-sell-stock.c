#include <best-time-to-buy-and-sell-stock.h>
#include <stddef.h>

int maxProfit_121(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;
    if (pricesSize < 2) return 0;

    int min_price = prices[0], max_profit = 0;
    for (int i = 1; i < pricesSize; ++i) {
        max_profit = prices[i] - min_price > max_profit ? prices[i] - min_price : max_profit;
        min_price = prices[i] < min_price ? prices[i] : min_price;
    }
    return max_profit;
}
