#include <best-time-to-buy-and-sell-stock-iii.h>
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
