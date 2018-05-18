#include <gtest/gtest.h>

extern "C" {
#include <binary_tree_maximum_path_sum.h>
}

TEST(leetcode_124, normal) {
    int nums1[] = {1, 2, 3};
    struct TreeNode *tree1 = tree_create(nums1, 3);
    EXPECT_EQ(maxPathSum_124(tree1), 6);
    tree_free(tree1);
    int nums2[] = {-1, -2, -3};
    struct TreeNode *tree2 = tree_create(nums2, 3);
    EXPECT_EQ(maxPathSum_124(tree2), -1);
    tree_free(tree2);
}
