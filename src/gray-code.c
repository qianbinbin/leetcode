#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <gray-code.h>

int *grayCode_89(int n, int *returnSize) {
    if (n < 0) return NULL;

    *returnSize = pow(2, n);
    int *ret = (int *) malloc(*returnSize * sizeof(int));
    assert(ret != NULL);
    for (int i = 0; i < *returnSize; ++i) {
        ret[i] = i ^ (i >> 1);
    }
    return ret;
}
