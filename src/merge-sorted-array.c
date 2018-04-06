#include <merge-sorted-array.h>
#include <string.h>

void merge_88_1(int *nums1, int m, int *nums2, int n) {
    if (nums1 == NULL || nums2 == NULL || m < 0 || n < 1) return;

    memmove(nums1 + n, nums1, m * sizeof(int));
    int index = 0, i = n, j = 0, size = m + n;
    while (i < size && j < n) {
        if (nums1[i] < nums2[j])
            nums1[index++] = nums1[i++];
        else
            nums1[index++] = nums2[j++];
    }
    if (j < n)
        memcpy(nums1 + index, nums2 + j, (n - j) * sizeof(int));
}

void merge_88_2(int *nums1, int m, int *nums2, int n) {
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
