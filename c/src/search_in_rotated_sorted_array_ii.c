#include "search_in_rotated_sorted_array_ii.h"

bool search_81_1(int *nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid, mid_val;
    while (low <= high) {
        mid = low + (high - low) / 2;
        mid_val = nums[mid];
        if (target == mid_val)
            return true;
        if (nums[low] < mid_val) {
            if (nums[low] <= target && target < mid_val)
                high = mid - 1;
            else
                low = mid + 1;
        } else if (nums[low] > mid_val) {
            if (mid_val < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            do { ++low; }
            while (low <= high && nums[low] == mid_val);
        }
    }
    return false;
}
