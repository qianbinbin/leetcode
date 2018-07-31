#include "median_of_two_sorted_arrays.h"

#include <assert.h>
#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays_4_1(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    assert(nums1 != NULL && nums2 != NULL
           && nums1Size >= 0 && nums2Size >= 0 && (nums1Size + nums2Size) > 0);

    if (nums1Size > nums2Size) {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int temp = nums1Size;
        nums1Size = nums2Size;
        nums2Size = temp;
    }

    int start = 0, end = nums1Size, mid1 = 0, mid2 = 0;
    const int sum = (nums1Size + nums2Size + 1) / 2;
    while (start <= end) {
        mid1 = start + (end - start) / 2;
        mid2 = sum - mid1;
        if (mid1 > 0 && mid2 < nums2Size && nums1[mid1 - 1] > nums2[mid2])
            end = mid1 - 1;
        else if (mid1 < nums1Size && mid2 > 0 && nums2[mid2 - 1] > nums1[mid1])
            start = mid1 + 1;
        else
            break;
    }

    int left;
    if (mid1 == 0)
        left = nums2[mid2 - 1];
    else if (mid2 == 0)
        left = nums1[mid1 - 1];
    else
        left = MAX(nums1[mid1 - 1], nums2[mid2 - 1]);

    if ((nums1Size + nums2Size) % 2 != 0)
        return left;

    int right;
    if (mid1 == nums1Size)
        right = nums2[mid2];
    else if (mid2 == nums2Size)
        right = nums1[mid1];
    else
        right = MIN(nums1[mid1], nums2[mid2]);
    return (left + right) / 2.0;
}
