#include <assert.h>
#include <stdlib.h>
#include <next-permutation.h>
#include <permutation-sequence.h>

char *getPermutation_60_1(int n, int k) {
    if (n < 1 || n > 9 || k < 0) return NULL;

    int nums[n];
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    for (int i = 0; i < k - 1; ++i) {
        nextPermutation_31(nums, n);
    }
    char *ret = (char *) malloc((n + 1) * sizeof(char));
    assert(ret != NULL);
    for (int i = 0; i < n; ++i) {
        ret[i] = (char) (nums[i] + '0');
    }
    ret[n] = '\0';
    return ret;
}
