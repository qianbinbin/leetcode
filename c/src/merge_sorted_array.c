#include "merge_sorted_array.h"

#include <string.h>

void
merge_88_1(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    --m;
    --n;
    while (m >= 0 && n >= 0) {
        if (nums1[m] >= nums2[n]) {
            nums1[m + n + 1] = nums1[m];
            --m;
        } else {
            nums1[m + n + 1] = nums2[n];
            --n;
        }
    }
    if (n >= 0)
        memcpy(nums1, nums2, (n + 1) * sizeof(int));
}
