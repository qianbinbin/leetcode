#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "remove_element.h"
}

TEST(remove_element_test, removeElement_27_1) {
    int nums1[] = {3, 2, 2, 3};
    array_print(nums1, 4);
    int size1 = removeElement_27_1(nums1, 4, 3);
    array_print(nums1, size1);

    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    array_print(nums2, sizeof(nums2) / sizeof(nums2[0]));
    int size2 = removeElement_27_1(nums2, sizeof(nums2) / sizeof(nums2[0]), 2);
    array_print(nums2, size2);
}
