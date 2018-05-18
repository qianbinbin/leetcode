#include <remove_element.h>
#include <stddef.h>

int removeElement_27(int *nums, int numsSize, int val) {
    if (nums == NULL || numsSize < 0) return -1;

    int index = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    return index;
}
