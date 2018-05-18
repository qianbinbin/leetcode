#include <candy.h>
#include <assert.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int candy_135(int *ratings, int ratingsSize) {
    if (ratings == NULL || ratingsSize < 0) return -1;

    int *candies = (int *) malloc(ratingsSize * sizeof(int));
    assert(candies != NULL);
    for (int i = 0; i < ratingsSize; ++i) candies[i] = 1;

    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = ratingsSize - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int nums = 0;
    for (int i = 0; i < ratingsSize; ++i) {
        nums += candies[i];
    }
    free(candies);
    return nums;
}
