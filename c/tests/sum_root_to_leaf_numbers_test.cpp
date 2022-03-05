#include <gtest/gtest.h>

extern "C" {
#include "sum_root_to_leaf_numbers.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(sum_root_to_leaf_numbers_test, sumNumbers_129_1) {
    int nums1[] = {1, 2, 3};
    struct TreeNode *root1 = tree_create(nums1, ARR_SIZE(nums1));
    EXPECT_EQ(25, sumNumbers_129_1(root1));
    tree_free(root1);

    int nums2[] = {4, 9, 0, 5, 1};
    struct TreeNode *root2 = tree_create(nums2, ARR_SIZE(nums2));
    EXPECT_EQ(1026, sumNumbers_129_1(root2));
    tree_free(root2);
}
