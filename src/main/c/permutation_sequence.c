#include <assert.h>
#include <stdlib.h>
#include <next_permutation.h>
#include <permutation_sequence.h>

char *getPermutation_60_1(int n, int k) {
    if (n < 1 || n > 9 || k < 0) return NULL;

    int nums[n];
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    for (int i = 0; i < k - 1; ++i) {
        nextPermutation_31_1(nums, n);
    }
    char *ret = (char *) malloc((n + 1) * sizeof(char));
    assert(ret != NULL);
    for (int i = 0; i < n; ++i) {
        ret[i] = (char) (nums[i] + '0');
    }
    ret[n] = '\0';
    return ret;
}

void array_remove(int *nums, int numsSize, int index) {
    if (nums == NULL || numsSize < 0 || index < 0 || index >= numsSize) return;

    for (int i = index; i < numsSize - 1; ++i) {
        nums[i] = nums[i + 1];
    }
}

char *getPermutation_60_2(int n, int k) {
    if (n < 1 || n > 9 || k < 1) return NULL;

    char *ret = (char *) malloc((n + 1) * sizeof(char));
    assert(ret != NULL);

    int factorial[n + 1];
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
    --k;
    k %= factorial[n];

    int nums[n];
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    int index;
    for (int i = 0; i < n; ++i) {
        index = k / factorial[n - i - 1];
        ret[i] = (char) (nums[index] + '0');
        array_remove(nums, n, index);
        k = k % factorial[n - i - 1];
    }
    ret[n] = '\0';
    return ret;
}
