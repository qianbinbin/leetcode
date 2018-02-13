#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <plus-one.h>

int *plusOne_66(int *digits, int digitsSize, int *returnSize) {
    if (digits == NULL || digitsSize < 1) return NULL;

    int *ret = (int *) malloc((digitsSize) * sizeof(int));
    assert(ret != NULL);

    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; --i) {
        ret[i] = digits[i] + carry;
        carry = ret[i] / 10;
        ret[i] = ret[i] % 10;
    }
    *returnSize = digitsSize;
    if (carry == 1) {
        int *result = (int *) malloc((digitsSize + 1) * sizeof(int));
        assert(result != NULL);
        result[0] = 1;
        memcpy(result + 1, ret, digitsSize * sizeof(int));
        int *tmp = result;
        result = ret;
        ret = tmp;
        free(result);
        ++*returnSize;
    }
    return ret;
}
