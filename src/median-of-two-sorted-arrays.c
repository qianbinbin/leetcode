#include <assert.h>
#include <stddef.h>
#include <median-of-two-sorted-arrays.h>

double findMedianSortedArrays_4(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    assert(nums1 != NULL && nums2 != NULL
           && nums1Size >= 0 && nums2Size >= 0 && (nums1Size + nums2Size) > 0);

    if (nums1Size > nums2Size) {
        int *tmp;
        tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int temp = nums1Size;
        nums1Size = nums2Size;
        nums2Size = temp;
    }

    int begin = 0, end = nums1Size;
    int i, j;
    const int sum = (nums1Size + nums2Size + 1) / 2;
    if (nums1 == 0) {
        i = begin + (end - begin) / 2;
        j = sum - i;
    } else {
        while (begin <= end) {
            i = begin + (end - begin) / 2;
            j = sum - i;
            if (i == 0) {
                if (nums2[j - 1] > nums1[i]) {
                    begin = i + 1;
                } else {
                    break;
                }
            } else if (0 < i && i < nums1Size) {
                if (nums1[i - 1] > nums2[j]) {
                    end = i - 1;
                } else if (nums2[j - 1] > nums1[i]) {
                    begin = i + 1;
                } else {
                    break;
                }
            } else {
                if (nums1[i - 1] > nums2[j]) {
                    end = i - 1;
                } else {
                    break;
                }
            }
            /*if (i < nums1Size && nums2[j - 1] > nums1[i]) {
                begin = i + 1;
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                end = i - 1;
            } else {
                break;
            }*/
        }
    }

    int max_left;
    if (i == 0) {
        max_left = nums2[j - 1];
    } else if (j == 0) {
        max_left = nums1[i - 1];
    } else {
        max_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
    }

    if ((nums1Size + nums2Size) % 2 != 0) {
        return max_left;
    }

    int min_right;
    if (i == nums1Size) {
        min_right = nums2[j];
    } else if (j == nums2Size) {
        min_right = nums1[i];
    } else {
        min_right = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
    }
    return (max_left + min_right) / 2.0;
}
