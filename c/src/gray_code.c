#include "gray_code.h"

#include <stdlib.h>

int *grayCode_89_1(int n, int *returnSize) {
    int *ret = (int *) malloc((1 << n) * sizeof(int));
    ret[0] = 0;
    *returnSize = 1;
    int highest_bit;
    for (int i = 0, j; i < n; ++i) {
        highest_bit = 1 << i;
        for (j = *returnSize - 1; j >= 0; --j)
            ret[(*returnSize)++] = ret[j] | highest_bit;
    }
    return ret;
}

int *grayCode_89_2(int n, int *returnSize) {
    *returnSize = 1 << n;
    int *ret = (int *) malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; ++i) {
        ret[i] = i ^ (i >> 1);
    }
    return ret;
}
