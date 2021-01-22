#include "median_of_two_sorted_arrays.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays_4_1(int *nums1, int nums1Size,
                                  int *nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int temp = nums1Size;
        nums1Size = nums2Size;
        nums2Size = temp;
    }

    int low = 0, high = nums1Size, i, j;
    const int sum = (nums1Size + nums2Size + 1) / 2;
    while (low <= high) {
        i = low + (high - low) / 2;
        j = sum - i;
        if (i > 0 && j < nums2Size && nums1[i - 1] > nums2[j])
            high = i - 1;
        else if (i < nums1Size && j > 0 && nums2[j - 1] > nums1[i])
            low = i + 1;
        else
            break;
    }

    int left;
    if (i == 0)
        left = nums2[j - 1];
    else if (j == 0)
        left = nums1[i - 1];
    else
        left = MAX(nums1[i - 1], nums2[j - 1]);

    if ((nums1Size + nums2Size) % 2 != 0)
        return left;

    int right;
    if (i == nums1Size)
        right = nums2[j];
    else if (j == nums2Size)
        right = nums1[i];
    else
        right = MIN(nums1[i], nums2[j]);
    return (left + right) / 2.0;
}
