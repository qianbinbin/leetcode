#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <longest-consecutive-sequence.h>

// Approach 1: sorting, O(nlog(n)) but accepted

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int longestConsecutive_128_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 2) return numsSize;

    int *tmp = (int *) malloc(numsSize * sizeof(int));
    assert(tmp != NULL);
    memcpy(tmp, nums, numsSize * sizeof(int));
    qsort(tmp, numsSize, sizeof(int), compare);
    int length = 1, longest = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (tmp[i] == tmp[i - 1]) {
            continue;
        } else if (tmp[i] == tmp[i - 1] + 1) {
            ++length;
        } else {
            longest = longest > length ? longest : length;
            length = 1;
        }
    }
    longest = longest > length ? longest : length;
    free(tmp);
    return longest;
}
