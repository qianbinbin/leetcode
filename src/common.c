#include <stdio.h>
#include <common.h>

void print_array(int *nums, int numsSize) {
    if (nums == NULL) return;
    printf("{");
    for (int i = 0; i < numsSize; ++i) {
        if (i < numsSize - 1) printf("%d, ", nums[i]);
        else printf("%d", nums[numsSize - 1]);
    }
    printf("}\n");
}
