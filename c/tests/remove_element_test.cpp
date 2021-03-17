#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "remove_element.h"
}

TEST(remove_element_test, removeElement_27_1) {
    int nums1[] = {3, 2, 2, 3}, numsSize1 = 4, val1 = 3;
    std::vector<int> const expected1{2, 2};
    int const size1 = removeElement_27_1(nums1, numsSize1, val1);
    ASSERT_EQ(expected1.size(), size1);
    EXPECT_EQ(expected1, std::vector<int>(nums1, nums1 + size1));

    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2}, numsSize2 = 8, val2 = 2;
    std::vector<int> const expected2{0, 1, 3, 0, 4};
    int const size2 = removeElement_27_1(nums2, numsSize2, val2);
    ASSERT_EQ(expected2.size(), size2);
    EXPECT_EQ(expected2, std::vector<int>(nums2, nums2 + size2));
}
