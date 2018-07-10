#include "merge_sorted_array.h"

#include <string.h>

void merge_88_1(int *nums1, int m, int *nums2, int n) {
    if (nums1 == NULL || nums2 == NULL || m < 0 || n < 1) return;

    int index = m + n - 1, i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[index--] = nums1[i--];
        else
            nums1[index--] = nums2[j--];
    }
    if (j >= 0)
        memcpy(nums1, nums2, (j + 1) * sizeof(int));
}
