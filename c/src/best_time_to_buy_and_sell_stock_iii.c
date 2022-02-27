#include "best_time_to_buy_and_sell_stock_iii.h"

#include <limits.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))


int maxProfit_123_1(int *prices, int pricesSize) {
    int hold1 = INT_MIN;
    int release1 = 0;
    int hold2 = INT_MIN;
    int release2 = 0;
    for (int i = 0; i < pricesSize; ++i) {
        release2 = MAX(release2, hold2 + prices[i]);
        hold2 = MAX(hold2, release1 - prices[i]);
        release1 = MAX(release1, hold1 + prices[i]);
        hold1 = MAX(hold1, -prices[i]);
    }
    return release2;
}

int maxProfit_123_2(int *prices, int pricesSize) {
    int valley = prices[0];
    int *dp1 = (int *) malloc(pricesSize * sizeof(int));
    dp1[0] = 0;
    for (int i = 1; i < pricesSize; ++i) {
        valley = MIN(valley, prices[i]);
        dp1[i] = MAX(dp1[i - 1], prices[i] - valley);
    }

    int peak = prices[pricesSize - 1];
    int *dp2 = (int *) malloc(pricesSize * sizeof(int));
    dp2[pricesSize - 1] = 0;
    for (int i = pricesSize - 2; i >= 0; --i) {
        peak = MAX(peak, prices[i]);
        dp2[i] = MAX(dp2[i + 1], peak - prices[i]);
    }

    int ret = 0;
    for (int i = 0; i < pricesSize; ++i) {
        ret = MAX(ret, dp1[i] + dp2[i]);
    }

    free(dp2);
    free(dp1);
    return ret;
}
