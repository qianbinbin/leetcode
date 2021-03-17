#include "remove_element.h"

int removeElement_27_1(int *nums, int numsSize, int val) {
    int size = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val)
            nums[size++] = nums[i];
    }
    return size;
}
