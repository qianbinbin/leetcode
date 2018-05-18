#include <best_time_to_buy_and_sell_stock_iii.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit_123_1(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;
    if (pricesSize < 2) return 0;

    int *f = (int *) malloc(pricesSize * sizeof(int));
    int *g = (int *) malloc(pricesSize * sizeof(int));

    int valley = prices[0];
    f[0] = 0;
    for (int i = 1; i < pricesSize; ++i) {
        valley = MIN(valley, prices[i]);
        f[i] = MAX(f[i - 1], prices[i] - valley);
    }
    int peak = prices[pricesSize - 1];
    g[pricesSize - 1] = 0;
    for (int i = pricesSize - 2; i >= 0; --i) {
        peak = MAX(peak, prices[i]);
        g[i] = MAX(g[i + 1], peak - prices[i]);
    }

    int max = 0;
    for (int i = 0; i < pricesSize; ++i) {
        max = MAX(max, f[i] + g[i]);
    }

    free(g);
    free(f);
    return max;
}

int maxProfit_123_2(int *prices, int pricesSize) {
    if (prices == NULL || pricesSize < 0) return -1;
    if (pricesSize < 2) return 0;

    int buy_1 = -prices[0];
    int sell_1 = 0;
    int buy_2 = -prices[0];
    int sell_2 = 0;
    for (int i = 1; i < pricesSize; ++i) {
        sell_2 = MAX(sell_2, buy_2 + prices[i]);
        buy_2 = MAX(buy_2, sell_1 - prices[i]);
        sell_1 = MAX(sell_1, buy_1 + prices[i]);
        buy_1 = MAX(buy_1, -prices[i]);
    }
    return sell_2;
}
