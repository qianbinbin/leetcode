#include <best-time-to-buy-and-sell-stock-ii.h>
#include <stddef.h>

int maxProfit_122_1(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;
    if (pricesSize < 2) return 0;

    int i = 1;
    int peak, valley;
    int max_profit = 0;
    while (i < pricesSize) {
        while (i < pricesSize && prices[i] <= prices[i - 1]) ++i;
        valley = prices[i - 1];
        while (i < pricesSize && prices[i] >= prices[i - 1]) ++i;
        peak = prices[i - 1];
        max_profit += peak - valley;
    }
    return max_profit;
}

int maxProfit_122_2(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;
    if (pricesSize < 2) return 0;

    int max_profit = 0;
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] > prices[i - 1])
            max_profit += prices[i] - prices[i - 1];
    }
    return max_profit;
}
