#include <search-for-a-range.h>
#include <stdlib.h>

int *searchRange_34(int *nums, int numsSize, int target, int *returnSize) {
    if (nums == NULL || numsSize < 0 || returnSize == NULL) return NULL;
    *returnSize = 2;

    int *ret = (int *) malloc(2 * sizeof(int));
    int begin = 0, end = numsSize - 1, mid = 0;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (nums[mid] == target)
            break;
        else if (nums[mid] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    if (nums[mid] == target) {
        ret[0] = mid;
        while (ret[0] > 0 && nums[ret[0] - 1] == nums[mid]) --ret[0];
        ret[1] = mid;
        while (ret[1] < numsSize - 1 && nums[ret[1] + 1] == nums[mid]) ++ret[1];
    } else {
        ret[0] = -1;
        ret[1] = -1;
    }
    return ret;
}
