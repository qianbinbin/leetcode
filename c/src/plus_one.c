#include "plus_one.h"

#include <stdlib.h>
#include <string.h>

int *plusOne_66_1(int *digits, int digitsSize, int *returnSize) {
    int *ret = (int *) malloc((digitsSize) * sizeof(int));
    memcpy(ret, digits, digitsSize * sizeof(int));
    for (int i = digitsSize - 1; i >= 0; --i) {
        if (ret[i] == 9) {
            ret[i] = 0;
        } else {
            ++ret[i];
            *returnSize = digitsSize;
            return ret;
        }
    }
    free(ret);
    *returnSize = digitsSize + 1;
    ret = (int *) calloc(*returnSize, sizeof(int));
    ret[0] = 1;
    return ret;
}
