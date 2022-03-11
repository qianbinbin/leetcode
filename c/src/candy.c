#include "candy.h"

#include <stdlib.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

int candy_135_1(int *ratings, int ratingsSize) {
    int *candies = (int *) malloc(ratingsSize * sizeof(int));
    for (int i = 0; i < ratingsSize; ++i) candies[i] = 1;

    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }
    int ret = candies[ratingsSize - 1];
    for (int i = ratingsSize - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1])
            candies[i] = MAX(candies[i], candies[i + 1] + 1);
        ret += candies[i];
    }
    free(candies);
    return ret;
}
