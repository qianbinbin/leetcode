#include <gtest/gtest.h>

extern "C" {
#include <same-tree.h>
}

TEST(leetcode_100, normal) {
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    struct TreeNode *tree1 = tree_create(nums1, 7);
    int nums2[] = {1, 2, 3, 4, 5, 6, 7};
    struct TreeNode *tree2 = tree_create(nums2, 7);
    EXPECT_TRUE(isSameTree_100(tree1, tree2));
    nums2[6] = 6;
    tree_free(tree2);
    tree2 = tree_create(nums2, 7);
    EXPECT_FALSE(isSameTree_100(tree1, tree2));
    tree_free(tree1);
    tree_free(tree2);
}
