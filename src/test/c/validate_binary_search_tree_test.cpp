#include <gtest/gtest.h>

extern "C" {
#include <validate_binary_search_tree.h>
}

TEST(leetcode_98, normal) {
    int nums1[] = {2, 1, 3};
    struct TreeNode *tree1 = tree_create(nums1, 3);
    EXPECT_TRUE(isValidBST_98(tree1));
    tree_free(tree1);
    int nums2[] = {1, 2, 3};
    struct TreeNode *tree2 = tree_create(nums2, 3);
    EXPECT_FALSE(isValidBST_98(tree2));
    tree_free(tree2);
}
