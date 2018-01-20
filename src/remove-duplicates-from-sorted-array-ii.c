#include <stddef.h>
#include <remove-duplicates-from-sorted-array-ii.h>

int removeDuplicates_80(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize < 3) return numsSize;

    int index = 1;
    for (int i = 2; i < numsSize; ++i) {
        if (nums[i] != nums[index - 1]) {
            nums[++index] = nums[i];
        }
    }
    return index + 1;
}
