#include "remove_duplicates_from_sorted_array.h"

int removeDuplicates_26_1(int *nums, int numsSize) {
    if (numsSize < 1)
        return numsSize;
    int last = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[last])
            nums[++last] = nums[i];
    }
    return last + 1;
}
