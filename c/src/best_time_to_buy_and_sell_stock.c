#include "best_time_to_buy_and_sell_stock.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit_121_1(int *prices, int pricesSize) {
    int min = prices[0], result = 0;
    for (int i = 1; i < pricesSize; ++i) {
        result = MAX(result, prices[i] - min);
        min = MIN(min, prices[i]);
    }
    return result;
}
