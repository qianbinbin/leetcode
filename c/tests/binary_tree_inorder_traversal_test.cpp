#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_inorder_traversal.h"
}

TEST(binary_tree_inorder_traversal_test, inorderTraversal_94_1) {
    int nums1[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int returnSize1 = 0;
    std::vector<int> expected1{1, 3, 2};
    int *actual1 = inorderTraversal_94_1(root1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);
    tree_free(root1);

    struct TreeNode *root2 = NULL;
    int returnSize2 = 0;
    std::vector<int> expected2;
    int *actual2 = inorderTraversal_94_1(root2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
    tree_free(root2);

    int nums3[] = {1};
    struct TreeNode *root3 = tree_create(nums3,
                                         sizeof(nums3) / sizeof(nums3[0]));
    int returnSize3 = 0;
    std::vector<int> expected3{1};
    int *actual3 = inorderTraversal_94_1(root3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
    tree_free(root3);
}

TEST(binary_tree_inorder_traversal_test, inorderTraversal_94_2) {
    int nums1[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root1 = tree_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int returnSize1 = 0;
    std::vector<int> expected1{1, 3, 2};
    int *actual1 = inorderTraversal_94_2(root1, &returnSize1);
    EXPECT_EQ(expected1, std::vector<int>(actual1, actual1 + returnSize1));
    free(actual1);
    tree_free(root1);

    struct TreeNode *root2 = NULL;
    int returnSize2 = 0;
    std::vector<int> expected2;
    int *actual2 = inorderTraversal_94_2(root2, &returnSize2);
    EXPECT_EQ(expected2, std::vector<int>(actual2, actual2 + returnSize2));
    free(actual2);
    tree_free(root2);

    int nums3[] = {1};
    struct TreeNode *root3 = tree_create(nums3,
                                         sizeof(nums3) / sizeof(nums3[0]));
    int returnSize3 = 0;
    std::vector<int> expected3{1};
    int *actual3 = inorderTraversal_94_2(root3, &returnSize3);
    EXPECT_EQ(expected3, std::vector<int>(actual3, actual3 + returnSize3));
    free(actual3);
    tree_free(root3);
}
