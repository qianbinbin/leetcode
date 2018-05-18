#include <sort_colors.h>
#include <stddef.h>

static void swap_int(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void sortColors_75(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 2) return;
    int zero = 0, two = numsSize - 1;
    for (int i = 0; i <= two;) {
        if (nums[i] == 0) {
            swap_int(nums + i, nums + zero);
            ++i;
            ++zero;
        } else if (nums[i] == 2) {
            swap_int(nums + i, nums + two);
            --two;
        } else ++i;
    }
}
